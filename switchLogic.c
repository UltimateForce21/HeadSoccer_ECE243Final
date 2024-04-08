void SetGameMode(){
    //will set the frequency speed based on switches setting
    volatile int * sw_addr = (int *) 0xFF200040;
    int sw = *(sw_addr);
    if(sw & 0b1 == 0b1){
        //choose from options
        //->update variable for cpu or vs mode
    }

}