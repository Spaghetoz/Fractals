#version 330 core
out vec4 FragColor;

uniform vec2 winSize; 

uniform float iterLimit;
uniform vec3 convergenceColor;
uniform vec3 divergenceColor;
uniform vec2 julia_c;
uniform float zoom;

uniform vec2 offset;


void julia(vec2 z, vec2 c) {

    for(int i = 0; i < iterLimit; i++) {
        // we calculate z_(n+1)= z_n^2+c 
        z = vec2( z.x*z.x - z.y*z.y , 2* z.x * z.y)+c;

        // if the complex modulus exceeds the limit of 2, it means that it diverges
        if(sqrt(pow(z.x, 2) + pow(z.y, 2)) > 2) {
            FragColor = vec4((i/iterLimit, 0, i/iterLimit)*divergenceColor, 1.0f);
            return;
        } 
    }
    // if we get out of the loop, it means that the point doesn't diverges
    FragColor = vec4(convergenceColor, 1.0f);
}

void mandelbrot(vec2 pos) {
    julia(vec2(0.0f, 0.0f), pos);
}

void burningShip(vec2 pos) {
    julia(vec2(0.0f, 0.0f), vec2(abs(pos.x), abs(pos.y)));
}

void main()
{   
    // place the origin to the center of the window and unzoom the coordinate system by dividing it
    // need power of 2 because else the zoom slows down
    // and balance the offset by multiplying it with the log base2 of zoom
    vec2 uv = offset+(gl_FragCoord.xy-vec2(winSize.x/2 , winSize.y/2))/(100.0f * pow(2, zoom));  
    julia(uv, julia_c);
    //mandelbrot(uv);
    //burningShip(uv);
    
}