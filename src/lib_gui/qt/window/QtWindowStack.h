#ifndef QT_WINDOW_STACK
#define QT_WINDOW_STACK

#include <vector>

#include <QWidget>

class QtWindowStackElement: public QWidget
{
	Q_OBJECT
public:
	QtWindowStackElement(QWidget* parent = nullptr);

	void setVisible(bool visible) override = 0;
};


class QtWindowStack: public QObject
{
	Q_OBJECT

signals:
	void empty();
	void pop();
	void push();

public:
	QtWindowStack(QObject* parent = nullptr);

	QtWindowStackElement* getTopWindow() const;

	size_t getWindowCount() const;

	void centerSubWindows();

public slots:
	void pushWindow(QtWindowStackElement* window);
	void popWindow();
	void clearWindows();

private:
	std::vector<QtWindowStackElement*> m_stack;
};

#endif	  // QT_WINDOW_STACK
