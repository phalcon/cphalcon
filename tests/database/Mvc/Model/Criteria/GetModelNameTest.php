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

namespace Phalcon\Tests\Database\Mvc\Model\Criteria;

use Phalcon\Mvc\Model\Criteria;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;

final class GetModelNameTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelCriteriaGetModelName(): void
    {
        $criteria = new Criteria();

        $criteria->setModelName(Invoices::class);

        $expected = Invoices::class;
        $actual   = $criteria->getModelName();
        $this->assertEquals($expected, $actual);
    }
}
