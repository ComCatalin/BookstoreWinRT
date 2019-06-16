#pragma once
#include "BookstoreViewModel.g.h"
#include "BookSku.h"

namespace winrt::Bookstore::implementation
{
    struct BookstoreViewModel : BookstoreViewModelT<BookstoreViewModel>
    {
        BookstoreViewModel();

        Bookstore::BookSku BookSku();
		void BookSku(Bookstore::BookSku value);

		Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> BookSkus();

		hstring Title();
		void Title(hstring value);

		winrt::event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
		void PropertyChanged(winrt::event_token const& token) noexcept;

	private:
		Bookstore::BookSku m_bookSku{ nullptr };
		Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> m_bookSkus;
		winrt::hstring m_title{ L"Book title here" };
		winrt::event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
