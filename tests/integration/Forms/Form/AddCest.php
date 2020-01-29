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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;

/**
 * Class AddCest
 */
class AddCest
{
    /**
     * Tests Phalcon\Forms\Form :: add()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsFormAdd(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - add()');
        $I->skipTest('Need implementation');
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/706
     */
    public function testIssue706(IntegrationTester $I)
    {
        $form = new Form();

        $form->add(new Text('name'));

        $form->add(new Text('before'), 'name', true);
        $form->add(new Text('after'), 'name');

        $expected = ['before', 'name', 'after'];
        $actual   = [];

        foreach ($form as $element) {
            $actual[] = $element->getName();
        }

        $I->assertEquals($expected, $actual);
    }
}
