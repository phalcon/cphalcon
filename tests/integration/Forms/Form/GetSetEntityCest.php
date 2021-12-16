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
use Phalcon\Forms\Form;
use stdClass;

class GetSetEntityCest
{
    /**
     * Tests Phalcon\Forms\Form :: getEntity()/setEntity()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-05
     */
    public function formsFormGetEntity(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getEntity()');

        $entity = new stdClass();
        $form   = new Form($entity);

        $expected = $entity;
        $actual   = $form->getEntity();
        $I->assertSame($expected, $actual);

        $second = new stdClass();

        $form->setEntity($second);

        $expected = $second;
        $actual   = $form->getEntity();
        $I->assertSame($expected, $actual);
    }
}
