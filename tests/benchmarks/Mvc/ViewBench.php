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

namespace Phalcon\Tests\Benchmarks\Mvc;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Url;
use Phalcon\Mvc\View;
use Phalcon\Tests\Benchmarks\Apps\Mvc\Fixture;
use PhpBench\Attributes\BeforeMethods;
use PhpBench\Attributes\Revs;
use RuntimeException;

#[BeforeMethods('setUp')]
#[Revs(200)]
final class ViewBench
{
    private const EXPECTED_PARTIAL = '<li>Item &lt;1&gt; &amp; &quot;more&quot;: 10</li>' . "\n";

    /**
     * The same page as the MVC app.
     */
    private const EXPECTED_RENDER_SHA1 = '097b4cff39daf3b03773bc354ea2cbd828a8b4d5';

    private array $item = [];

    private array $vars = [];

    private View $view;

    public function setUp(): void
    {
        Di::reset();
        $container = new FactoryDefault();

        $url = new Url();
        $url->setBaseUri('/');
        $container->setShared('url', $url);

        $fixture    = new Fixture();
        $this->view = $fixture->view($container, $fixture->compiledPath());
        $this->view->setDI($container);
        $container->setShared('view', $this->view);

        $this->vars = $fixture->productVars('7');
        $this->item = $this->vars['items'][0];
    }

    /**
     * One partial (compiled Volt file).
     */
    public function benchPartial(): void
    {
        ob_start();
        $this->view->partial('partials/item', ['item' => $this->item]);
        $body = ob_get_clean();

        if (self::EXPECTED_PARTIAL !== $body) {
            throw new RuntimeException(sprintf('Unexpected partial: "%s"', $body));
        }
    }

    /**
     * The product page with the main layout and 10 partials (compiled Volt files).
     */
    public function benchRender(): void
    {
        $this->view->start();
        $this->view->render('products', 'show', $this->vars);
        $this->view->finish();
        $body = (string) $this->view->getContent();

        $actual = sha1($body);
        if (self::EXPECTED_RENDER_SHA1 !== $actual) {
            throw new RuntimeException(sprintf('Unexpected page (sha1 %s): %s', $actual, $body));
        }
    }
}
