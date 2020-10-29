/*
  Copyright 2012-2020 David Robillard <d@drobilla.net>

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above
  copyright notice and this permission notice appear in all copies.

  THIS SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

/**
   @file pugl_gl.h
   @brief OpenGL-specific API.
*/

#ifndef PUGL_PUGL_GL_H
#define PUGL_PUGL_GL_H

#include "pugl/pugl.h"

// IWYU pragma: begin_exports

/* Unfortunately, GL includes vary across platforms, so include them here to
   enable pure portable programs. */

#ifndef PUGL_NO_INCLUDE_GL_H
#	ifdef __APPLE__
#		include "OpenGL/gl.h"
#	else
#		ifdef _WIN32
#			include <windows.h>
#		endif
#		include "GL/gl.h"
#	endif
#endif

#ifndef PUGL_NO_INCLUDE_GLU_H
#	ifdef __APPLE__
#		include "OpenGL/glu.h"
#	else
#		ifdef _WIN32
#			include <windows.h>
#		endif
#		include "GL/glu.h"
#	endif
#endif

// IWYU pragma: end_exports

PUGL_BEGIN_DECLS

/**
   @defgroup gl OpenGL
   OpenGL graphics support.
   @ingroup pugl_c
   @{
*/

/**
   OpenGL extension function.
*/
typedef void (*PuglGlFunc)(void);

/**
   Return the address of an OpenGL extension function.
*/
PUGL_API PuglGlFunc
puglGetProcAddress(const char* name);

/**
   OpenGL graphics backend.

   Pass the returned value to puglSetBackend() to draw to a view with OpenGL.
*/
PUGL_API PUGL_CONST_FUNC const PuglBackend*
puglGlBackend(void);

PUGL_END_DECLS

/**
   @}
*/

#endif // PUGL_PUGL_GL_H
