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

final class AddCssTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-13
     */
    public function testAssetsManagerAddCss(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $manager->addCss('/css/style1.css');
        $manager->addCss('/css/style2.css');

        $collection = $manager->get('css');

        $expected = 'css';
        foreach ($collection as $resource) {
            $actual = $resource->getType();
            $this->assertSame($expected, $actual);
        }

        $expected = 2;
        $this->assertCount($expected, $collection);
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/10938
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-06-02
     */
    public function testAssetsManagerAddCssDuplicate(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        for ($i = 0; $i < 10; $i++) {
            $manager
                ->addCss('css/style.css')
                ->addJs('script.js')
            ;
        }

        $expected = 1;
        $this->assertCount($expected, $manager->getCss());
        $this->assertCount($expected, $manager->getJs());

        for ($i = 0; $i < 2; $i++) {
            $manager
                ->addCss('style_' . $i . '.css')
                ->addJs('script_' . $i . '.js')
            ;
        }

        $expected = 3;
        $this->assertCount($expected, $manager->getCss());
        $this->assertCount($expected, $manager->getJs());
    }
}
