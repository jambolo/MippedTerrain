/** @file *//********************************************************************************************************

                                                       Tile.cpp

						                    Copyright 2003, John J. Bolton
	--------------------------------------------------------------------------------------------------------------

	$Header: //depot/Libraries/MippedTerrain/Tile.cpp#2 $

	$NoKeywords: $

 ********************************************************************************************************************/

#include "PrecompiledHeaders.h"

#include "Tile.h"

#include "Dxx/D3d.h"
#include "Dxx/VertexBuffer.h"
#include "Misc/Types.h"




namespace MippedTerrain
{


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Tile::Tile( int size, void * pData, DWORD fvf, IDirect3DDevice9 * pDevice )
	: m_Size( size ),
	m_pIndexBuffer( 0 ),
	m_pVertexBuffer( 0 )
{
	HRESULT	hr;

	// Create a vertex buffer for this tile.
	hr = Dxx::CreateStaticVertexBuffer( pDevice, pData, size, fvf, &m_pVertexBuffer );

	// Generate the index buffer for this tile
	GenerateIndexBuffer();

}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

Tile::~Tile()
{
	if ( m_pVertexBuffer != 0 )
	{
		m_pVertexBuffer->Release();
	}

	if ( m_pIndexBuffer != 0 )
	{
		m_pIndexBuffer->Release();
	}
}


/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Tile::Draw()
{

}



/********************************************************************************************************************/
/*																													*/
/*																													*/
/********************************************************************************************************************/

void Tile::GenerateIndexBuffer()
{
	HRESULT	hr;

	uint16 *	pData;
	
	hr = m_pIndexBuffer->Lock( 0, ( m_Size * ( 2 * m_Size + 3 ) - 1 ) * sizeof( uint16 ), (void **)&pData, D3DLOCK_DISCARD );
	Dxx::StripGrid( m_Size, m_Size, pData );

	
}


} // namespace MippedTerrain
