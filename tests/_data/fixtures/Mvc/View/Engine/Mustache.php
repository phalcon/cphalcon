<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Fixtures\Mvc\View\Engine;

use Mustache_Engine;
use Phalcon\Di\DiInterface;
use Phalcon\Mvc\View\Engine\AbstractEngine;
use Phalcon\Mvc\View\Engine\EngineInterface;
use Phalcon\Mvc\ViewBaseInterface;

class Mustache extends AbstractEngine implements EngineInterface
{
    /**
     * The internal Mustache Engine
     *
     * @var Mustache_Engine
     */
    protected $mustache;

    /**
     * The view params
     *
     * @var array
     */
    protected $params = [];

    /**
     * Mustache constructor.
     */
    public function __construct(ViewBaseInterface $view, DiInterface $dependencyInjector = null)
    {
        $this->mustache = new Mustache_Engine();

        parent::__construct($view, $dependencyInjector);
    }

    /**
     * Renders a view using the template engine
     */
    public function render(string $path, $params, bool $mustClean = false)
    {
        if (!isset($params['content'])) {
            $params['content'] = $this->view->getContent();
        }

        $content = $this->mustache->render(
            file_get_contents($path),
            $params
        );

        if ($mustClean) {
            $this->view->setContent($content);
        } else {
            echo $content;
        }
    }
}
