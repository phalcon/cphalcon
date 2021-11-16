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

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Robots;

/**
 * Class GetUpdatedFieldsCest
 */
class GetUpdatedFieldsCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: getUpdatedFields() - keepSnapshots
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelGetUpdatedFieldsKeepSnapshots(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - getUpdatedFields() - keepSnapshots');
        $this->setNewFactoryDefault();
        $this->setDiMysql();
        $I->expectThrowable(
            new Exception(
                "The 'keepSnapshots' option must be enabled to track changes"
            ),
            function () {
                $robot  = Robots::findFirst();
                $fields = $robot->getUpdatedFields();
            }
        );
    }
}
