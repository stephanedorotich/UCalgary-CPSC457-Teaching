// Print out the number of command line arguments
// Print out each command line argument
// Author: Xining Chen
// CPSC 457
// Use freely

int main(int argc, char ** argv)
{
    std::cout << "Number of arguments: " << std::endl;
    std::cout << "argv contains: " << std::endl;

    for (i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "] = " << argc[i] << endl;
    }

    return 0;
}