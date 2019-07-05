#if !defined( MIPPEDTERRAIN_TILE_H_INCLUDED )
#define MIPPEDTERRAIN_TILE_H_INCLUDED

#pragma once

/** @file *//********************************************************************************************************

                                                        Tile.h

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/MippedTerrain/Tile.h#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include <d3dx9.h>

namespace MippedTerrain
{

	
	
/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

class Tile
{
public:

	Tile( int size, void * pData, DWORD fvf, IDirect3DDevice9 * pDevice );
	virtual ~Tile();

	/// Draw the tile
	virtual void Draw();

	// Generate index buffer for this timle
	void GenerateIndexBuffer();

	int							m_Size;				///< The length of a side.
	IDirect3DIndexBuffer9 *		m_pIndexBuffer;		///< The tile's index buffer.
	IDirect3DVertexBuffer9 *	m_pVertexBuffer;	///< The tile's vertex buffer.
};



} // namespace MippedTerrain


#endif // !defined( MIPPEDTERRAIN_TILE_H_INCLUDED )
