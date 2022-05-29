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

namespace Phalcon\Tests\Integration\Forms\Element;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function sprintf;
use function uniqid;

class GetSetTagFactoryCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Forms\Element :: getTagFactory()/setTagFactory()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function formsElementGetSetTagFactory(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element - getTagFactory()/setTagFactory()');

        $escaper       = new Escaper();
        $tagFactoryOne = new TagFactory($escaper);

        $name    = uniqid();
        $element = new Text($name);

        /**
         * Initial
         */
        $actual = $element->getTagFactory();
        $I->assertNull($actual);

        $element->setTagFactory($tagFactoryOne);

        $expected = $tagFactoryOne;
        $actual   = $element->getTagFactory();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Forms\Element :: getTagFactory()/setTagFactory() - from Element
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function formsElementGetSetTagFactoryFromElement(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element - getTagFactory()/setTagFactory() - from Element');

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
        $I->assertNull($actual);

        $element->setForm($form);

        $expected = sprintf('<input type="text" id="%s" name="%s" />', $name, $name);
        $actual = $element->render();
        $I->assertSame($expected, $actual);

        /**
         * From form
         */
        $expected = $tagFactoryOne;
        $actual   = $element->getTagFactory();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Forms\Element :: getTagFactory()/setTagFactory() - from DI
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function formsElementGetSetTagFactoryFromDi(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element - getTagFactory()/setTagFactory() - from Di');

        $this->setNewFactoryDefault();

        $tagFactoryOne = $this->container->get("tag");

        $name    = uniqid();
        $element = new Text($name);

        /**
         * Initial
         */
        $actual = $element->getTagFactory();
        $I->assertNull($actual);

        /**
         * From DI
         */
        $expected = sprintf('<input type="text" id="%s" name="%s" />', $name, $name);
        $actual = $element->render();
        $I->assertSame($expected, $actual);

        $expected = $tagFactoryOne;
        $actual   = $element->getTagFactory();
        $I->assertSame($expected, $actual);
    }
}
