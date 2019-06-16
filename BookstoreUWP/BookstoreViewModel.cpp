#include "pch.h"
#include "BookstoreViewModel.h"
#include "BookstoreViewModel.g.cpp"

namespace winrt::Bookstore::implementation
{
	BookstoreViewModel::BookstoreViewModel() : m_title{ L"Add title" }
	{
		m_bookSku = winrt::make<Bookstore::implementation::BookSku>(L"Atticus");
		m_bookSkus = winrt::single_threaded_observable_vector<Windows::Foundation::IInspectable>();
		m_bookSkus.Append(m_bookSku);
	}

	Bookstore::BookSku BookstoreViewModel::BookSku()
	{
		return m_bookSku;
	}
	void BookstoreViewModel::BookSku(Bookstore::BookSku value)
	{
		if (m_bookSku != value)
		{
			m_bookSku = value;
			Title(m_bookSku.Title());
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"BookSku" });
		}
	}

	Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> BookstoreViewModel::BookSkus()
	{
		return m_bookSkus;
	}

	hstring BookstoreViewModel::Title()
	{
		return m_title;
	}
	void BookstoreViewModel::Title(hstring value)
	{
		if (m_title != value)
		{
			m_title = value;
			m_propertyChanged(*this, Windows::UI::Xaml::Data::PropertyChangedEventArgs{ L"Title" });
		}
	}

	winrt::event_token BookstoreViewModel::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void BookstoreViewModel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}
}
