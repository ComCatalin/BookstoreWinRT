#pragma once
#include "MainPage.g.h"
#include "BookstoreViewModel.h"

namespace winrt::Bookstore::implementation
{
	struct MainPage : MainPageT<MainPage>
	{
		MainPage();

		Bookstore::BookstoreViewModel MainViewModel();

		void ClickHandler(Windows::Foundation::IInspectable const&, Windows::UI::Xaml::RoutedEventArgs const&);

	private:
		Bookstore::BookstoreViewModel m_mainViewModel{ nullptr };
	};
}
namespace winrt::Bookstore::factory_implementation
{
	struct MainPage : MainPageT<MainPage, implementation::MainPage>
	{
	};
}
