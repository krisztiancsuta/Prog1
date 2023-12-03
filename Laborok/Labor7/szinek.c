typedef enum colour 
{
    WHITE, RED, YELLOW,
    LIME, CYAN, BLUE, 
    MAGENTA, BLACK
}colour;

typedef struct rgb
{
    unsigned char r,g,b;
}rgb;

rgb make_rgb(colour color){
    switch (color)
    {
    case WHITE:{
        rgb x1 = {255,255,255};
        return x1;}
    case RED:{
        rgb x2 = {255,0,0};
        return x2;}
        
    case YELLOW:{
        rgb x3 = {255,255,0};
        return x3;}
       
    case LIME:{
        rgb x4 = {0,255,0};
        return x4;}
        
    case CYAN:{
        rgb x5 = {0,255,255};
        return x5;}
      
    case BLUE:{
        rgb x6 = {0,0,255};
        return x6;}
        
    case BLACK:{
        rgb x7 = {0,0,0};
        return x7;}
       
       
    case MAGENTA:{
        rgb x8 = {255,0,255};
        return x8;}
       
    }
}

int main(){

    return 0;
}