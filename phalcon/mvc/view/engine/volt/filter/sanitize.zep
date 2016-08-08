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
class Sanitize extends FilterInterface
{

    public function filter(string! viewCode) -> string {
       let viewCode = preg_replace("/\>\r?\n\s*(\r?\n)?/", ">", viewCode);
       let viewCode = preg_replace("/[^\S ]+\</s", "<", viewCode);
       let viewCode = preg_replace( "/(\s)+/s", "\\1", viewCode);
        return viewCode;
    }

}