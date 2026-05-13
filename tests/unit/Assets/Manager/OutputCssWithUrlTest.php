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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Mvc\Url;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use const PHP_EOL;

final class OutputCssWithUrlTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function tearDown(): void
    {
        $this->resetDi();
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - uses URL service static base URI
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-04-29
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16570
     */
    public function testAssetsManagerOutputCssUsesUrlStaticBaseUri(): void
    {
        $url = new Url();
        $url->setStaticBaseUri('/my_app/');

        $container = new Di();
        $container->setShared('url', $url);

        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->setDI($container);

        $manager->addCss('css/style.css');
        $manager->useImplicitOutput(false);

        $expected = '<link rel="stylesheet" type="text/css" href="/my_app/css/style.css" />' . PHP_EOL;
        $actual   = $manager->outputCss();

        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Manager :: outputCss() - falls back to "/" prefix when no URL service
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2025-04-29
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16570
     */
    public function testAssetsManagerOutputCssFallsBackWithoutUrlService(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('css/style.css');
        $manager->useImplicitOutput(false);

        $expected = '<link rel="stylesheet" type="text/css" href="/css/style.css" />' . PHP_EOL;
        $actual   = $manager->outputCss();

        $this->assertSame($expected, $actual);
    }
}
