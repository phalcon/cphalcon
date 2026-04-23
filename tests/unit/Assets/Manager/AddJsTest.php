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
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function supportDir;

final class AddJsTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->newDi();
        $this->setDiService('url');
    }

    public function tearDown(): void
    {
        $this->resetDi();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddJs(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addJs('/js/jquery.js');
        $manager->addJs('/js/jquery-ui.js');

        $collection = $manager->get('js');

        foreach ($collection as $resource) {
            $expected = 'js';
            $actual   = $resource->getType();
            $this->assertSame($expected, $actual);
        }

        $expected = 2;
        $actual   = count($collection);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-02-01
     */
    public function testAssetsManagerAddJsVersioning(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $container = $this->getDI();

        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->setDI($container);
        $manager->useImplicitOutput(false);

        $manager->addJs(
            supportDir('assets/assets/assets-version-1.js'),
            true,
            false,
            [],
            '1.0.0'
        );

        $manager->addJs(
            supportDir('assets/assets/assets-version-2.js'),
            true,
            false,
            [],
            '2.0.0'
        );

        $manager->addJs(
            supportDir('assets/assets/assets-version-3.js'),
            true,
            false,
            []
        );

        $pathData = supportDir('assets/');
        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL . "%s" . PHP_EOL,
            "<script type=\"application/javascript\" "
            . "src=\"{$pathData}assets/assets-version-1.js?ver=1.0.0\"></script>",
            "<script type=\"application/javascript\" "
            . "src=\"{$pathData}assets/assets-version-2.js?ver=2.0.0\"></script>",
            "<script type=\"application/javascript\" "
            . "src=\"{$pathData}assets/assets-version-3.js\"></script>"
        );

        $this->assertSame($expected, $manager->outputJs());
    }
}
