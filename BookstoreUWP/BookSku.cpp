#include "pch.h"
#include "BookSku.h"
#include "BookSku.g.cpp"

namespace winrt::Bookstore::implementation
{
	BookSku::BookSku(winrt::hstring const& title) : m_title{ title }
	{
	}
	hstring BookSku::Title()
    {
		return m_title;
    }
    void BookSku::Title(hstring value)
    {
		if (m_title != value)
		{
			m_title = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Title" });
		}
    }
    winrt::event_token BookSku::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
		return m_propertyChanged.add(handler);
    }
    void BookSku::PropertyChanged(winrt::event_token const& token) noexcept
    {
		m_propertyChanged.remove(token);
    }
}
