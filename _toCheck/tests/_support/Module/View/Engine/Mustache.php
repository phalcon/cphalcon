<?php

namespace Phalcon\Test\Module\View\Engine;

use Mustache_Engine;
use Phalcon\DiInterface;
use Phalcon\Mvc\View\Engine;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Mvc\View\EngineInterface;

/**
 * \Phalcon\Test\Module\View\Engine\Mustache
 * Adapter to use Mustache library as templating engine.
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Module\View\Engine
 *
 * @property ViewBaseInterface $_view
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Mustache extends Engine implements EngineInterface
{
    /**
     * The internal Mustache Engine
     * @var Mustache_Engine
     */
    protected $mustache;

    /**
     * The view params
     * @var array
     */
    protected $params = [];

    /**
     * Mustache constructor.
     *
     * @param ViewBaseInterface $view
     * @param DiInterface|null $dependencyInjector
     */
    public function __construct(ViewBaseInterface $view, DiInterface $dependencyInjector = null)
    {
        $this->mustache = new Mustache_Engine();

        parent::__construct($view, $dependencyInjector);
    }

    /**
     * Renders a view using the template engine
     *
     * @param string $path
     * @param mixed $params
     * @param bool $mustClean
     */
    public function render($path, $params, $mustClean = false)
    {
        if (!isset($params['content'])) {
            $params['content'] = $this->_view->getContent();
        }

        $content = $this->mustache->render(file_get_contents($path), $params);
        if ($mustClean) {
            $this->_view->setContent($content);
        } else {
            echo $content;
        }
    }
}
