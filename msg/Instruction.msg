Header header

#determines type of instruction
bool reqsHumanHelp

#standardized set of descriptors for different human interactions (eventually)
#extraneous if reqsHumanHelp is false
#not yet implemented (only goto is right now) 
string helpDescriptor

#all fields below are only for goto commands
#extraneous if reqsHumanHelp is true
uint32 startFloor
float32 startX
float32 startY

uint32 endFloor
float32 endX
float32 endY
