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

namespace Phalcon\Tests\Unit\Forms\Element;

use Phalcon\Di\Di;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Exception;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function sprintf;
use function uniqid;

final class GetSetTagFactoryTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function testFormsElementGetSetTagFactory(): void
    {
        $escaper       = new Escaper();
        $tagFactoryOne = new TagFactory($escaper);

        $name    = uniqid();
        $element = new Text($name);

        /**
         * Initial
         */
        $actual = $element->getTagFactory();
        $this->assertNull($actual);

        $element->setTagFactory($tagFactoryOne);

        $expected = $tagFactoryOne;
        $actual   = $element->getTagFactory();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function testFormsElementGetSetTagFactoryFromDi(): void
    {
        $this->setNewFactoryDefault();

        $tagFactoryOne = $this->container->get("tag");

        $name    = uniqid();
        $element = new Text($name);

        /**
         * Initial
         */
        $actual = $element->getTagFactory();
        $this->assertNull($actual);

        /**
         * From DI
         */
        $expected = sprintf('<input type="text" id="%s" name="%s">', $name, $name);
        $actual   = $element->render();
        $this->assertSame($expected, $actual);

        $expected = $tagFactoryOne;
        $actual   = $element->getTagFactory();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function testFormsElementGetSetTagFactoryFromElement(): void
    {
        $escaper       = new Escaper();
        $tagFactoryOne = new TagFactory($escaper);

        $form = new Form();
        $form->setTagFactory($tagFactoryOne);

        $name    = uniqid();
        $element = new Text($name);

        /**
         * Initial
         */
        $actual = $element->getTagFactory();
        $this->assertNull($actual);

        $element->setForm($form);

        $expected = sprintf('<input type="text" id="%s" name="%s">', $name, $name);
        $actual   = $element->render();
        $this->assertSame($expected, $actual);

        /**
         * From form
         */
        $expected = $tagFactoryOne;
        $actual   = $element->getTagFactory();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsElementGetLocalTagFactoryThrowsWhenNotResolvable(): void
    {
        Di::reset();

        $name    = uniqid();
        $element = new Text($name);

        $this->expectException(Exception::class);

        $element->render();
    }
}
