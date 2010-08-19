/*
  Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008,
  2009, 2010 Free Software Foundation, Inc.

  This file is part of GNU Inetutils.

  GNU Inetutils is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or (at
  your option) any later version.

  GNU Inetutils is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see `http://www.gnu.org/licenses/'. */

/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* This code is derived from software contributed to Berkeley by
   Michael Fischbein. */

#include <config.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "fts.h"
#include <string.h>

#include "ls.h"
#include "extern.h"

int
namecmp (a, b)
     const FTSENT *a, *b;
{
  return (strcmp (a->fts_name, b->fts_name));
}

int
revnamecmp (a, b)
     const FTSENT *a, *b;
{
  return (strcmp (b->fts_name, a->fts_name));
}

int
modcmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_mtime > a->fts_statp->st_mtime)
    return (1);
  else if (b->fts_statp->st_mtime < a->fts_statp->st_mtime)
    return (-1);
  else
    return (namecmp (a, b));
}

int
revmodcmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_mtime > a->fts_statp->st_mtime)
    return (-1);
  else if (b->fts_statp->st_mtime < a->fts_statp->st_mtime)
    return (1);
  else
    return (revnamecmp (a, b));
}

int
acccmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_atime > a->fts_statp->st_atime)
    return (1);
  else if (b->fts_statp->st_atime < a->fts_statp->st_atime)
    return (-1);
  else
    return (namecmp (a, b));
}

int
revacccmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_atime > a->fts_statp->st_atime)
    return (-1);
  else if (b->fts_statp->st_atime < a->fts_statp->st_atime)
    return (1);
  else
    return (revnamecmp (a, b));
}

int
statcmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_ctime > a->fts_statp->st_ctime)
    return (1);
  else if (b->fts_statp->st_ctime < a->fts_statp->st_ctime)
    return (-1);
  else
    return (namecmp (a, b));
}

int
revstatcmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_ctime > a->fts_statp->st_ctime)
    return (-1);
  else if (b->fts_statp->st_ctime < a->fts_statp->st_ctime)
    return (1);
  else
    return (revnamecmp (a, b));
}

int
sizecmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_size > a->fts_statp->st_size)
    return (1);
  if (b->fts_statp->st_size < a->fts_statp->st_size)
    return (-1);
  else
    return (namecmp (a, b));
}

int
revsizecmp (a, b)
     const FTSENT *a, *b;
{
  if (b->fts_statp->st_size > a->fts_statp->st_size)
    return (-1);
  if (b->fts_statp->st_size < a->fts_statp->st_size)
    return (1);
  else
    return (revnamecmp (a, b));
}
