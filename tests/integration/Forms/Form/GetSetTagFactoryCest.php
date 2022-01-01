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

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetSetTagFactoryCest
{
    /**
     * Tests Phalcon\Forms\Form :: getTagFactory()/setTagFactory()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-30
     */
    public function formsFormGetSetTagFactory(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getTagFactory()/setTagFactory()');

        $escaper       = new Escaper();
        $tagFactoryOne = new TagFactory($escaper);

        $form = new Form();

        /**
         * Initial
         */
        $actual = $form->getTagFactory();
        $I->assertNull($actual);

        $form->setTagFactory($tagFactoryOne);

        $expected = $tagFactoryOne;
        $actual   = $form->getTagFactory();
        $I->assertSame($expected, $actual);
    }
}
