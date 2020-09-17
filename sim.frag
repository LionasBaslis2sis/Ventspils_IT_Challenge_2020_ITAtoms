#version 330

uniform float t;
uniform sampler2D overlay;

void main() {
    bool overlay = texture2D(overlay, gl_TexCoord[0].xy).a == 1;
    gl_FragColor = (1.f - float(overlay)) * vec4(sin(t)/2 + 0.5, -cos(t)/2 + 0.5, 0, 1);
}