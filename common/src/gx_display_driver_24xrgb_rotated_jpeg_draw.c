/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** GUIX Component                                                        */
/**                                                                       */
/**   Display Management (Display)                                        */
/**                                                                       */
/**************************************************************************/

#define GX_SOURCE_CODE


/* Include necessary system files.  */

#include "gx_api.h"
#include "gx_context.h"
#include "gx_system.h"
#include "gx_image_reader.h"
#include "gx_display.h"

/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _gx_dislay_driver_24xrgb_rotated_jpeg_draw          PORTABLE C      */
/*                                                           6.x          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Kenneth Maxwell, Microsoft Corporation                              */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    24xrgb rotated screen driver JPEG image draw routine.               */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    context                               Drawing context               */
/*    xpos                                  x-coord of top-left draw point*/
/*    ypos                                  y-coord of top-left draw point*/
/*    pixelmap                              Pointer to GX_PIXELMAP struct */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                                Completion status             */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    _gx_image_reader_jpeg_mcu_decode                                    */
/*    [_gx_display_driver_24xrgb_rotated_mcu_draw]                        */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*    GUIX Internal Code                                                  */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  02-02-2021     Kenneth Maxwell          Initial Version 6.1.4         */
/*  xx-xx-xxxx     Ting Zhu                 Modified comment(s),          */
/*                                            removed a parameter from    */
/*                                            jpeg mcu decode function,   */
/*                                            resulting in version 6.x    */
/*                                                                        */
/**************************************************************************/
#if defined(GX_SOFTWARE_DECODER_SUPPORT)
VOID _gx_display_driver_24xrgb_rotated_jpeg_draw(GX_DRAW_CONTEXT *context, INT xpos, INT ypos, GX_PIXELMAP *pixelmap)
{
    _gx_image_reader_jpeg_mcu_decode(pixelmap -> gx_pixelmap_data,
                                     pixelmap -> gx_pixelmap_data_size,
                                     context, xpos, ypos);
}
#endif

