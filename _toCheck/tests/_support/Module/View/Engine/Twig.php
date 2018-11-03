<?php

namespace Phalcon\Test\Module\View\Engine;

use Twig_Environment;
use Phalcon\DiInterface;
use Twig_Loader_Filesystem;
use Phalcon\Mvc\View\Engine;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Mvc\View\EngineInterface;

/**
 * \Phalcon\Test\Module\View\Engine\Twig
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
class Twig extends Engine implements EngineInterface
{
    protected $twig;

    /**
     * Twig constructor.
     *
     * @param ViewBaseInterface $view
     * @param DiInterface|null $dependencyInjector
     */
    public function __construct(ViewBaseInterface $view, DiInterface $dependencyInjector = null)
    {
        $this->twig = new Twig_Environment(new Twig_Loader_Filesystem($view->getViewsDir()));

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

        if (!isset($params['view'])) {
            $params['view'] = $this->_view;
        }

        $relativePath = str_replace($this->_view->getViewsDir(), '', $path);
        $content = $this->twig->render($relativePath, $params);

        if ($mustClean) {
            $this->_view->setContent($content);
        } else {
            echo $content;
        }
    }
}
