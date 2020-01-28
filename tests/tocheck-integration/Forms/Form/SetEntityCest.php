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
use Phalcon\Forms\Form;
use stdClass;

class SetEntityCest
{
    /**
     * Tests Phalcon\Forms\Form :: setEntity()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-23
     */
    public function formsFormSetEntity(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - setEntity()');

        $entity = new stdClass();

        $form = new Form();

        $I->assertNull(
            $form->getEntity()
        );

        $form->setEntity($entity);

        $I->assertSame(
            $entity,
            $form->getEntity()
        );
    }
}
