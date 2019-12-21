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

namespace Phalcon\Test\Integration\Mvc\Model\Row;

use IntegrationTester;
use Phalcon\Mvc\Model\Row;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: jsonSerialize()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-06-01
     */
    public function mvcModelRowJsonSerialize(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - jsonSerialize()');

        $row = new Row();

        $row->writeAttribute('id', 1);
        $row->writeAttribute('name', 'Sid');
        $row->writeAttribute('city', 'Busan');

        $I->assertEquals(
            [
                'id'   => 1,
                'name' => 'Sid',
                'city' => 'Busan',
            ],
            $row->jsonSerialize()
        );
    }
}
