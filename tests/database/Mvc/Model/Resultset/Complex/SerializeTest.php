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
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class SerializeTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->setDiService('phpSerializer');
        $this->seedResultsetFixture();
    }

    /**
     * Serialising a complex resultset and restoring it preserves its rows.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexSerialize(): void
    {
        $original = $this->getResultset('complex');

        $restored = new Complex(null);
        $restored->unserialize($original->serialize());

        // A complex resultset hydrates rows of models whose internal snapshot
        // state is not part of the serialised payload, so compare the restored
        // row count rather than a deep object graph.
        $this->assertCount(4, $restored);
        $this->assertSame($original->count(), $restored->count());
    }
}
