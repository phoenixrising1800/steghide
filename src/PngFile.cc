/*
 * steghide 0.5.1 - a steganography program
 * Copyright (C) 1999-2003 Stefan Hetzl <shetzl@chello.at>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#include "common.h"

#ifdef USE_LIBPNG

#include <cstdio>
#include <iostream>

#include "AUtils.h"
#include "BinaryIO.h"
#include "PngFile.h"
// #include "JpegSampleValue.h"
#include "SMDConstructionHeuristic.h"
#include "error.h"

PngFile::PngFile (BinaryIO* io) : CvrStgFile() 
{
    read( io );
}

PngFile::~PngFile () {}

std::list<CvrStgFile::Property> PngFile::getProperties () const
{
    std::list<CvrStgFile::Property> retval;
    // format

	retval.push_back (CvrStgFile::Property (_("format"), "png")) ;
	return retval;
}

void PngFile::read (BinaryIO* io) 
{
    CvrStgFile::read (io);
	FILE *infile = NULL ;
	if (io->is_std()) {
		throw NotImplementedError (_("can not use standard input as source for png files with libpng.")) ;
	}
	else {
		infile = io->getStream() ;uu
		rewind (infile) ;
    }


}
#endif // def USE_LIBPNG