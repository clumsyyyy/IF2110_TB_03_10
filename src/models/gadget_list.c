/**
 * @file gadget_list.c
 * @brief Implementasi tipe data GadgetList.
 * Tipe data ini digunakan untuk inventory pada game.
 */

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "gadget.h"
#include "gadget_list.h"

/**
 * @brief Constructor untuk membuat GadgetList baru.
 * 
 * @return Instance GadgetList berisi 5 Gadget yang tidak terdefinisi. 
 */
GadgetList newGadgetList()
{
    GadgetList gList = (GadgetList)malloc(sizeof(struct gadgetlist));
    for (int i = 0; i < 5; i++)
    {
        setGadget(gList, i, NULL);
    }
    return gList;
}

/**
 * @brief Mengecek apakah suatu GadgetList kosong atau tidak.
 * 
 * @param gList GadgetList instance.
 * @return true jika semua elemen gList adalah gadget yang tidak
 *         terdefinsi, false selainnya. 
 */
boolean isGadgetListEmpty(GadgetList gList)
{
    for (int i = 0; i < 5; i++)
    {
        if (getGadget(gList, i) != NULL)
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Mengecek apakah gadget gList penuh atau tidak.
 * 
 * @param gList GadgetList instance.
 * @return true jika semua elemen gList bukanlah gadget yang tidak
 *         terdefinsi, false selainnya.
 */
boolean isGadgetListFull(GadgetList gList)
{
    for (int i = 0; i < 5; i++)
    {
        if (getGadget(gList, i) == NULL)
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Mengecek apakah indeks valid untuk sebuah GagdetList.
 * 
 * @param index Indeks yang akan dicek.
 * @return true jika indeks valid untuk GadgetList, false
 *         selainnya.
 */
boolean isGagetListIndexValid(int index)
{
    return index >= 0 && index < 5;
}

/**
 * @brief Mengambil Gadget instance dari gList pada indeks index.
 * Mengembalikan NULL_GADGET jika index berada di luar range
 * yang berlaku (0..4).
 * 
 * @param gList GadgetList instance.
 * @param index Indeks dari Gadget pada gList yang akan diambil.
 * @return Gadget instance pada indeks index di GadgetList gList.
 */
Gadget getGadget(GadgetList gList, int index)
{
    return (index >= 0 && index < 5) ? gList->contents[index] : NULL;
}

/**
 * @brief Set elemen gList pada indeks index menjadi Gadget g.
 * 
 * @param gList GadgetList instance.
 * @param index Indeks gList yang akan di-set.
 * @param g Gadget instance.
 */
void setGadget(GadgetList gList, int index, Gadget g)
{
    gList->contents[index] = g;
}

/**
 * @brief Menambahkan gadget pada slot yang kosong.
 * 
 * @param gList GadgetList instance.
 * @param g Gadget yang ingin ditambahkan
 */
void insertGadget(GadgetList gList, Gadget g)
{
    int i = 0;
    boolean inserted = false;
    while (i < 5 && !inserted)
    {
        if (getGadget(gList, i) == NULL)
        {
            setGadget(gList, i, g);
            inserted = true;
        }
        else
        {
            i++;
        }
    }
}

/**
 * @brief Mengambil dan menghapus gadget dari GadgetList.
 * 
 * @param gList GadgetList instance.
 * @param index Indeks gadget yang akan diambil & dihapus.
 * @return Gadget yang dihapus.
 */
Gadget deleteGadget(GadgetList gList, int index)
{
    Gadget g;
    if (isGagetListIndexValid(index))
    {
        g = gList->contents[index];
        setGadget(gList, index, NULL);
    }
    else
    {
        g = NULL;
    }
    return g;
}

/**
 * @brief Menuliskan list Gadget (inventory) ke console output.
 * ! Hanya digunakan untuk command INVENTORY.
 * 
 * @param gList GadgetList instance.
 */
void displayGadget(GadgetList gList)
{
    for (int i = 0; i < 5; i++)
    {
        Gadget gadget = getGadget(gList, i);
        printf("%d. %s\n", i + 1, gadget == NULL ? "-" : name(gadget));
    }
}

/**
 * @brief Menghitung panjang gadget list
 * !
 * 
 * @param gList GadgetList instance.
 */
int gListLength(GadgetList gList)
{
    int length = 0;
    int i = 0;
    while (i < 5)
    {
        if (getGadget(gList, i) != NULL)
        {
            length++;
        }
        i++;
    }
    return length;
}