-- $Source: /home/CVSROOT/c2ada/c.ads,v $ 
-- $Revision: 1.1.1.1 $ $Date: 1999/02/02 12:01:51 $ $Author: nabbasi $ 
with Interfaces.C;
-- with X.Strings;
with System;

package C is

    -- ****************************************
    -- Types corresponding to C built-in types:
    -- ****************************************

    subtype char           is Interfaces.C.Char;
    subtype signed_char    is Interfaces.C.signed_char;
    subtype unsigned_char  is Interfaces.C.Unsigned_Char;

    subtype short          is Interfaces.C.Short;
    subtype unsigned_short is Interfaces.C.Unsigned_Short;

    subtype int            is Interfaces.C.Int;
    subtype natural_int    is int range 0..int'Last;	-- array indices
    subtype unsigned_int   is Interfaces.C.Unsigned;

    subtype long           is Interfaces.C.Long;
    subtype unsigned_long  is Interfaces.C.Unsigned_Long;

    subtype float          is Interfaces.C.C_Float;
    subtype double         is Interfaces.C.Double;

    -- subtype charp	   is X.Strings.charp;	
    type charp             is access all char;
    -- subtype const_charp	   is X.Strings.const_charp;
    type const_charp       is access constant char;
    Nul: Interfaces.C.Char renames Interfaces.C.Nul;

    subtype ptrdiff_t      is Interfaces.C.ptrdiff_t;
    subtype size_t         is Interfaces.C.size_t;

    -- **************************************************
    -- Array types, moved up here so the type definitions
    -- can be shared between packages.
    -- **************************************************

    subtype Char_Array     is Interfaces.C.Char_Array;
    type Unsigned_Char_Array is array (natural_int range <>) of unsigned_char;
    type Short_Array is array (natural_int range <>) of Short;
    type Unsigned_Short_Array is array (natural_int range <>) of unsigned_Short;
    type Int_Array is array (natural_int range <>) of int;
    type Unsigned_Int_Array is array (natural_int range <>) of unsigned_int;
    type Long_Array is array (natural_int range <>) of Long;
    type Unsigned_Long_Array is array (natural_int range <>) of unsigned_Long;
    type Float_Array is array (natural_int range <>) of Float;
    type Double_Array is array (natural_int range <>) of Double;

    function "&" (S: Char_Array; C: Char) return Char_Array
	renames Interfaces.C."&";

    -- *******************************************************
    -- Allocate new nul-terminated strings and return pointers
    -- *******************************************************

    -- function New_String (S: String) return charp 
	-- renames X.Strings.New_String;

    -- function New_String (S: String) return const_charp 
	-- renames X.Strings.New_String;

    -- *************************************************
    -- Map C untyped "void *" pointers to System.Address
    -- *************************************************

    subtype Void_Star is System.Address;
    type function_pointer is access procedure;	-- untyped

    -- ********************************************************
    -- In C, a variable-size array is declared as a[1] or
    -- a[ANYSIZE_ARRAY], where ANYSIZE_ARRAY is defined as 1.
    -- Then it is used as if it were bigger.
    -- In Ada we declare it as array(0..ANYSIZE_ARRAY) and then
    -- use the extensible array package.
    -- In C ANYSIZE_ARRAY is 1 and in Ada it is 0.
    -- ********************************************************
    
    ANYSIZE_ARRAY: constant := 0;                           -- winnt.h:26

    -- ****************************************************
    -- Types moved up here, to break circular dependencies,
    -- and to remove duplicate definitions:
    -- ****************************************************

    type Int_Access is access all int;
    type Unsigned_Long_Access is access all unsigned_long;
    type unsigned_char_access is access all unsigned_char;
    type const_unsigned_char_access is access constant unsigned_char;
    type wchar_access is access all interfaces.c.wchar_t;   -- wchar *
    type wchar_access_access is access all wchar_access;    -- wchar **

    -- *********************
    -- bit fields in records
    -- *********************
    type bits1   is mod 2**1;  for bits1'size use 1;
    type bits2   is mod 2**2;  for bits2'size use 2;
    type bits3   is mod 2**3;  for bits3'size use 3;
    type bits4   is mod 2**4;  for bits4'size use 4;
    type bits5   is mod 2**5;  for bits5'size use 5;
    type bits6   is mod 2**6;  for bits6'size use 6;
    type bits7   is mod 2**7;  for bits7'size use 7;
    type bits8   is mod 2**8;  for bits8'size use 8;
    type bits9   is mod 2**9;  for bits9'size use 9;
    type bits10  is mod 2**10;  for bits10'size use 10;
    type bits11  is mod 2**11;  for bits11'size use 11;
    type bits12  is mod 2**12;  for bits12'size use 12;
    type bits13  is mod 2**13;  for bits13'size use 13;
    type bits14  is mod 2**14;  for bits14'size use 14;
    type bits15  is mod 2**15;  for bits15'size use 15;
    type bits16  is mod 2**16;  for bits16'size use 16;
    type bits17  is mod 2**17;  for bits17'size use 17;
    type bits18  is mod 2**18;  for bits18'size use 18;
    type bits19  is mod 2**19;  for bits19'size use 19;
    type bits20  is mod 2**20;  for bits20'size use 20;
    type bits21  is mod 2**21;  for bits21'size use 21;
    type bits22  is mod 2**22;  for bits22'size use 22;
    type bits23  is mod 2**23;  for bits23'size use 23;
    type bits24  is mod 2**24;  for bits24'size use 24;
    type bits25  is mod 2**25;  for bits25'size use 25;
    type bits26  is mod 2**26;  for bits26'size use 26;
    type bits27  is mod 2**27;  for bits27'size use 27;
    type bits28  is mod 2**28;  for bits28'size use 28;
    type bits29  is mod 2**29;  for bits29'size use 29;
    type bits30  is mod 2**30;  for bits30'size use 30;
    type bits31  is mod 2**31;  for bits31'size use 31;
    type bits32  is mod 2**32;  for bits32'size use 32;

    -- *********************************************
    -- Support function for C macros and expressions
    -- *********************************************
    function Sizeof (Bits: Integer) return Int;
    function Bool_to_Int (Val: Boolean) return Int;
    procedure Call (Ignored_Function_Result: Int);
    procedure Call (Ignored_Function_Result: Charp);
    function To_C (C: Character) return Interfaces.C.Char;

    function "+" (C: char; I: Int) return char;
    pragma Inline("+");

    function "+" (C: char; I: Int) return Int;
    pragma Inline("+");

private

    pragma Inline(Sizeof);
    pragma Inline(Bool_to_Int);
    pragma Inline(Call);
    pragma Inline(To_C);

end C;
