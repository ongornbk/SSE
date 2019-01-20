#pragma once
#include <sal.h>
#include <xmmintrin.h>

typedef __m128 m128;

namespace sse
{

	_Use_decl_annotations_
		inline m128 _vectorcall operator +(_In_ m128 A, _In_ m128 B) noexcept
	{
		return _mm_add_ps(A, B);
	}

	

	_Use_decl_annotations_
		inline m128 _vectorcall operator -(_In_ m128 A, _In_ m128 B) noexcept
	{
		return _mm_sub_ps(A, B);
	}

	_Use_decl_annotations_
		inline _Out_ m128 _vectorcall operator *(_In_ m128 A, _In_ m128 B) noexcept
	{
		return _mm_mul_ps(A, B);
	}

	_Use_decl_annotations_
		inline _Out_ m128 _vectorcall operator /(_In_ m128 A, _In_ m128 B) noexcept
	{
		return _mm_div_ps(A, B);
	}

	_Use_decl_annotations_
		inline _Out_ bool _vectorcall operator ==(_In_ m128 A, _In_ m128 B) noexcept
	{
		m128 C = _mm_cmpeq_ps(A, B);
		return ((_mm_movemask_ps(C) == 0x0f) != 0);
	}

	_Use_decl_annotations_
		inline _Out_ bool _vectorcall operator !=(_In_ m128 A, _In_ m128 B) noexcept
	{
		m128 C = _mm_cmpneq_ps(A, B);
		return ((_mm_movemask_ps(C)) != 0);
	}

	_Use_decl_annotations_
		inline _Out_ bool _vectorcall operator >(_In_ m128 A, _In_ m128 B) noexcept
	{
		m128 C = _mm_cmpgt_ps(A, B);
		return ((_mm_movemask_ps(C) == 0x0f) != 0);
	}

	_Use_decl_annotations_
		inline _Out_ bool _vectorcall operator >=(_In_ m128 A, _In_ m128 B) noexcept
	{
		m128 C = _mm_cmpge_ps(A, B);
		return ((_mm_movemask_ps(C) == 0x0f) != 0);
	}

	_Use_decl_annotations_
		inline _Out_ bool _vectorcall operator <(_In_ m128 A, _In_ m128 B) noexcept
	{
		m128 C = _mm_cmplt_ps(A, B);
		return ((_mm_movemask_ps(C) == 0x0f) != 0);
	}

	_Use_decl_annotations_
		inline _Out_ bool _vectorcall operator <=(_In_ m128 A, _In_ m128 B) noexcept
	{
		m128 C = _mm_cmple_ps(A, B);
		return ((_mm_movemask_ps(C) == 0x0f) != 0);
	}

	_Use_decl_annotations_
		inline _Out_ m128 _vectorcall load(_In_reads_(4) float A[4]) noexcept
	{
		return _mm_load_ps(A);
	}

	_Use_decl_annotations_
		inline void _vectorcall store(float A[4], _In_ m128 B) noexcept
	{
		_mm_store_ps(A, B);
	}

}

using sse::operator+;
using sse::operator-;
using sse::operator*;
using sse::operator/;
using sse::operator==;
using sse::operator!=;
using sse::operator>;
using sse::operator>=;
using sse::operator<;
using sse::operator<=;