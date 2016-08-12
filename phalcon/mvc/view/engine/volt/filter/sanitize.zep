namespace Phalcon\Mvc\View\Engine\Volt\Filter;

use Phalcon\Mvc\View\Engine\Volt\Filter\FilterInterface;
/**
 * Phalcon\Mvc\View\Engine\Volt\Filter\Sanitize
 *
 *<code>
 *  $filter = new \Phalcon\Mvc\View\Engine\Volt\Filter\Sanitize();
 *  $filter->filter('<html><body></body></html>');
 *</code>
 */
class Sanitize implements FilterInterface
{
    protected _search = [
        "/\\>\\r?\\n\\s*(\\r?\\n)?/",  // strip whitespaces after tags, except space
        "/[^\\S ]+\\</s",  // strip whitespaces before tags, except space
        "/(\\s)+/s"       // shorten multiple whitespace sequences
    ];

    protected _replace = [
        ">",
        "<",
        "\\\\1"
    ];


    public function filter(string! viewCode) -> string {
 	return preg_replace(this->_search, this->_replace, viewCode);
    }

}
