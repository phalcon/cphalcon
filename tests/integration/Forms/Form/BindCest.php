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
 * Class BindCest
 */
class BindCest
{
    /**
     * Tests Phalcon\Forms\Form :: bind()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsFormBind(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - bind()');
        $form = new Form();
        $form->add(new Text('test1'));

        $data = [
            'test1' => 'test1',
        ];

        $form->bind($data, new \stdClass());

        $I->assertEquals("test1", $form->getValue("test1"));
    }

    public function testBindWhitelist(IntegrationTester $I)
    {

        $I->wantToTest('Forms\Form - bind() with whitelist');
        $form = new Form();
        $form->add(new Text('nameFirst'));
        $form->add(new Text('nameLast'));

        $data = [
            'test1' => 'test1',
            'nameFirst' => 'nameFirst',
            'nameLast' => 'nameLast',
        ];

        $entity = new \stdClass();
        $white_list = ['nameFirst', 'nameLast'];
        $form->bind($data, $entity, $white_list);

        $I->assertEquals("nameFirst", $form->getValue("nameFirst"));
        $I->assertEquals("nameLast", $form->getValue("nameLast"));
        $I->assertNull($form->getValue("test1"));
    }
}
