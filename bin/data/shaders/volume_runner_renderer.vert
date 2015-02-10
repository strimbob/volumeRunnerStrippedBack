#version 120

varying mat4 box_mats[2];
uniform vec2 mouse;
varying mat4 steerMatrix;

varying mat4 invViewMatrix;

void main()
{
    
    float timer = gl_Vertex.x;
    int intyoub = int(gl_Vertex.z);

    mat4 movingPoint ;
    
    
    
    
    for(int q = 0;q<2;q++){
        
        movingPoint =   mat4(
                             vec4( cos(0),  sin(0),  0.0,0.0),
                             vec4(-sin(0),  cos(0),  0.0,0.0),
                             vec4(       0.0,         0.0,  1.0,0.0),
                             vec4(      -mouse.x*q,          -mouse.y*q,  1.0,0.0)
                             );

    
     box_mats[q] = gl_ModelViewMatrix *  movingPoint;



    }
    
    mat4 invertMatrix =  mat4(
                              vec4( cos(0),  sin(0),  0.0,0.0),
                              vec4(-sin(0),  cos(0),  0.0,0.0),
                              vec4(       0.0,         0.0,  1.0,0.0),
                              vec4(    0,         1,  9.0,0.0)
                              );

   
    steerMatrix = gl_ModelViewMatrix *  movingPoint  ;
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
    
    invViewMatrix = gl_ModelViewProjectionMatrixInverse *  invertMatrix;
}