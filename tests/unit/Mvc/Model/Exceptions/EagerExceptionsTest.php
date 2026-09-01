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

namespace Phalcon\Tests\Unit\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Exceptions\EagerRowLimitExceeded;
use Phalcon\Mvc\Model\Exceptions\InvalidEagerParameter;
use Phalcon\Mvc\Model\Exceptions\InvalidEagerPath;
use Phalcon\Mvc\Model\Exceptions\MissingEagerKeyColumn;
use Phalcon\Mvc\Model\Exceptions\UnknownEagerRelation;
use Phalcon\Mvc\Model\Exceptions\UnsupportedEagerHydration;
use Phalcon\Mvc\Model\Exceptions\UnsupportedEagerOption;
use Phalcon\Mvc\Model\Exceptions\UnsupportedEagerResultset;
use PHPUnit\Framework\TestCase;

final class EagerExceptionsTest extends TestCase
{
    /**
     * Every eager exception extends the model exception and carries a message
     * that names the offending value.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-25
     */
    public function testMvcModelExceptionsEagerMessages(): void
    {
        $rowLimit = new EagerRowLimitExceeded('Customers', 120000, 100000);
        $this->assertInstanceOf(Exception::class, $rowLimit);
        $this->assertSame(
            "Eager loading 'Customers' returned 120000 rows which exceeds the "
            . 'limit of 100000',
            $rowLimit->getMessage()
        );

        $parameter = new InvalidEagerParameter();
        $this->assertSame(
            "The 'eager' parameter must be an array of relation paths",
            $parameter->getMessage()
        );

        $path = new InvalidEagerPath('customer..country');
        $this->assertSame(
            "Invalid eager loading path 'customer..country'",
            $path->getMessage()
        );

        $column = new MissingEagerKeyColumn('customer', 'inv_cst_id');
        $this->assertSame(
            "Eager loading the relation 'customer' requires the column "
            . "'inv_cst_id' to be present in the selected columns",
            $column->getMessage()
        );

        $relation = new UnknownEagerRelation('Invoices', 'custmoer');
        $this->assertSame(
            "Model 'Invoices' does not define a relation with alias 'custmoer'",
            $relation->getMessage()
        );

        $hydration = new UnsupportedEagerHydration();
        $this->assertSame(
            'Eager loading is only supported with Resultset::HYDRATE_RECORDS',
            $hydration->getMessage()
        );

        $option = new UnsupportedEagerOption('limit');
        $this->assertSame(
            "Eager loading does not support the 'limit' option: a per-parent "
            . 'limit requires a window function, which PHQL cannot express',
            $option->getMessage()
        );

        $resultset = new UnsupportedEagerResultset('Phalcon\Mvc\Model\Row');
        $this->assertSame(
            'Eager loading requires a Phalcon\Mvc\Model\Resultset\Simple '
            . "resultset, 'Phalcon\Mvc\Model\Row' given",
            $resultset->getMessage()
        );
    }
}
