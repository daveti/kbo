/*
 * bo.c
 * Kernel module playing with byte-order kernel APIs
 * Aug 3, 2014
 * root@davejingtian.org
 * http://davejingtian.org
 */
#include <linux/module.h>
#include <linux/byteorder/generic.h>

static u8 global_array[8];

static void init_array(void)
{
	global_array[0] = 0x01;
	global_array[1] = 0x23;
	global_array[2] = 0x45;
	global_array[3] = 0x67;
	global_array[4] = 0x89;
	global_array[5] = 0xab;
	global_array[6] = 0xcd;
	global_array[7] = 0xef;
}

static inline void array_le16_to_cpu(u16 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = le16_to_cpu(*arr);
}

static inline void array_le32_to_cpu(u32 *arr, int num)
{
	int i;
	for (i = 0; i < num; i++, arr++)
		*arr = le32_to_cpu(*arr);
}

static inline void array_le64_to_cpu(u64 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = le64_to_cpu(*arr);
}

/*--------------------------------------------------------*/

static inline void array_be16_to_cpu(u16 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = be16_to_cpu(*arr);
}

static inline void array_be32_to_cpu(u32 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = be32_to_cpu(*arr);
}

static inline void array_be64_to_cpu(u64 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = be64_to_cpu(*arr);
}

/*--------------------------------------------------------*/

static inline void array_cpu_to_le16(u16 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = cpu_to_le16(*arr);
}

static inline void array_cpu_to_le32(u32 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = cpu_to_le32(*arr);
}

static inline void array_cpu_to_le64(u64 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = cpu_to_le64(*arr);
}

/*---------------------------------------------------------*/

static inline void array_cpu_to_be16(u16 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = cpu_to_be16(*arr);
}

static inline void array_cpu_to_be32(u32 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = cpu_to_be32(*arr);
}

static inline void array_cpu_to_be64(u64 *arr, int num)
{
        int i;
        for (i = 0; i < num; i++, arr++)
                *arr = cpu_to_be64(*arr);
}
 
static int __init bo_init(void)
{
	printk(KERN_INFO "Entering: %s\n", __FUNCTION__);
    
	/* Init array */
	init_array();
	printk(KERN_INFO "global_data:\n");
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);

	/* le to cpu */
	printk(KERN_INFO "le16_to_cpu:\n");
	array_le16_to_cpu((u16 *)global_array, 4);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
	init_array();
        printk(KERN_INFO "le32_to_cpu:\n");
        array_le32_to_cpu((u32 *)global_array, 2);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
        printk(KERN_INFO "le64_to_cpu:\n");
        array_le64_to_cpu((u64 *)global_array, 1);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();

	/* cpu to le */
        printk(KERN_INFO "cpu_to_le16:\n");
        array_cpu_to_le16((u16 *)global_array, 4);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
        printk(KERN_INFO "cpu_to_le32:\n");
        array_cpu_to_le32((u32 *)global_array, 2);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
        printk(KERN_INFO "cpu_to_le64:\n");
        array_cpu_to_le64((u64 *)global_array, 1);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();

	/* be to cpu */
        printk(KERN_INFO "be16_to_cpu:\n");
        array_be16_to_cpu((u16 *)global_array, 4);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
        printk(KERN_INFO "be32_to_cpu:\n");
        array_be32_to_cpu((u32 *)global_array, 2);
	print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
        printk(KERN_INFO "be64_to_cpu:\n");
        array_be64_to_cpu((u64 *)global_array, 1);
        print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();

	/* cpu to be */
        printk(KERN_INFO "cpu_to_be16:\n");
        array_cpu_to_be16((u16 *)global_array, 4);
        print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
        printk(KERN_INFO "cpu_to_be32:\n");
        array_cpu_to_be32((u32 *)global_array, 2);
        print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
        printk(KERN_INFO "cpu_to_be64:\n");
        array_cpu_to_be64((u64 *)global_array, 1);
        print_hex_dump(KERN_INFO, "", DUMP_PREFIX_NONE, 16, 1, global_array, 8, 0);
        init_array();
	
	return 0;
}
 
static void __exit bo_exit(void)
{
	printk(KERN_INFO "exiting bo module\n");
}
 
module_init(bo_init);
module_exit(bo_exit);
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("BO Module");
MODULE_AUTHOR("daveti");
