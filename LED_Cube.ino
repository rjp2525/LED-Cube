// Declare the pins for the 16 columns (x/y)
int c[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A4, A5};
// Declare the vertical layers (z)
int z[4] = {A0, A1, A2, A3};
// Declare a timed delay so effects are visible (250ms)
int t = 250

// Intialize columns and layers
void setup()
{
  // Initialize the columns
  for(int i=0; i<16; i++)
  {
    pinMode(c[i], OUTPUT);
  }
  
  // Initialize the layers
  for(int i=0; i<4; i++)
  {
    pinMode(z[i], OUTPUT);
  }
}

// Main function, loops continuously
void loop()
{
  // TODO
}
