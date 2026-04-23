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
use PHPUnit\Framework\Attributes\Test;

use function sprintf;

use const PHP_EOL;

final class UseImplicitOutputTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAssetsManagerUseImplicitOutput(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager->collection('footer')
                ->addCss('/css/style1.css')
        ;

        $footer = $manager->collection('footer');

        $footer->addCss('/css/style2.css');

        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<link rel="stylesheet" type="text/css" href="/css/style1.css" />',
            '<link rel="stylesheet" type="text/css" href="/css/style2.css" />'
        );

        $manager->useImplicitOutput(false);

        $this->assertSame($expected, $manager->outputCss('footer'));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAssetsManagerUseImplicitOutputRemote(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));
        $manager
            ->collection('header')
            ->setPrefix('http:://cdn.example.com/')
            ->setIsLocal(false)
            ->addJs('js/script1.js')
            ->addJs('js/script2.js')
        ;

        $manager->useImplicitOutput(false);

        $expected = sprintf(
            "%s" . PHP_EOL . "%s" . PHP_EOL,
            '<script type="application/javascript" src="http:://cdn.example.com/js/script1.js"></script>',
            '<script type="application/javascript" src="http:://cdn.example.com/js/script2.js"></script>'
        );

        $this->assertSame($expected, $manager->outputJs('header'));
    }
}
