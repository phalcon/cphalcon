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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Mvc\Model;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class CloneResultTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelCloneResult(): void
    {
        $base = new Invoices();
        $data = [
            'inv_id'    => 5,
            'inv_title' => 'cloned title',
        ];

        $clone = Invoices::cloneResult(
            $base,
            $data,
            Model::DIRTY_STATE_PERSISTENT
        );

        $this->assertInstanceOf(Invoices::class, $clone);
        $this->assertNotSame($base, $clone);
        $this->assertEquals(5, $clone->inv_id);
        $this->assertEquals('cloned title', $clone->inv_title);
        $this->assertSame(
            Model::DIRTY_STATE_PERSISTENT,
            $clone->getDirtyState()
        );
    }
}
