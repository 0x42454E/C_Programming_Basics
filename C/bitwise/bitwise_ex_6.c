/**
 * This program implements bitwise checkup operation without using the if statement. 
 * 
 * 
 * Author: Ben
 * Date: 2024-08
 */



/**
 * Return true if 2nd and 6th bits are on.
 * 
 */
int CharRecieve(const unsigned char a) // part 1
{
	unsigned char b = '"';
	
	b = (a & b);
	
	return (34 == b); 
}


/**
 * Return true if 2nd or 6th or both bits are on.  
 * 
 */
int CharRecieve(const unsigned char a) // part 2
{
	unsigned char b = 34;
	unsigned char c = 2;	
	unsigned char e = 32;	
	
	b = (a & b);
	c = (a & c);
	e = (a & e);

	return ((34 == b) + (2 == c) + (32 == e)); 
}


/**
 * Return num with 3rd and 5th bits swapped.  
 * 
 */
unsigned char SwapThreeFive(unsigned char num)
{

    unsigned char bit2 = num & 0x04;
    
    unsigned char bit4 = num & 0x10;
    
    unsigned char bit2_moved = bit2 << 2;
    
    unsigned char bit4_moved = bit4 >> 2;
    
    unsigned char swapped_bits = bit2_moved | bit4_moved;
    
    unsigned char num_with_swapped_bits_cleared = num & ~0x14;
    
    return num_with_swapped_bits_cleared | swapped_bits;
}   
 
