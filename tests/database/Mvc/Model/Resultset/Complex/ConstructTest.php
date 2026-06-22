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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Complex;

use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->seedResultsetFixture();
    }

    /**
     * A joined query builds a Complex resultset whose records are rows.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexConstruct(): void
    {
        $resultset = $this->getResultset('complex');

        $this->assertInstanceOf(Complex::class, $resultset);
        $this->assertCount(4, $resultset);

        $resultset->rewind();

        $this->assertInstanceOf(Row::class, $resultset->current());
    }
}
