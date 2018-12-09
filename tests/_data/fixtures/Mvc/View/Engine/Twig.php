<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Mvc\View\Engine;

use Twig_Environment;
use Phalcon\DiInterface;
use Twig_Loader_Filesystem;
use Phalcon\Mvc\View\Engine;
use Phalcon\Mvc\ViewBaseInterface;
use Phalcon\Mvc\View\EngineInterface;

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
