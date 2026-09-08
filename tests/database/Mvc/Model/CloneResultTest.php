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

use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exceptions\InvalidDumpResultKey;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesCloneResultProbe;
use Phalcon\Tests\Support\Models\InvoicesWithPrivateSetters;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;
use ReflectionProperty;

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

    /**
     * afterFetch() fires exactly once - not once per key - and only after every
     * value in $data has been assigned.
     */
    public function testMvcModelCloneResultAfterFetchFiresOnceAfterAllAssignment(): void
    {
        $clone = Model::cloneResult(
            new InvoicesCloneResultProbe(),
            [
                'inv_id'    => 7,
                'inv_title' => 'fetched title',
                'inv_total' => 12.5,
            ],
            Model::DIRTY_STATE_PERSISTENT
        );

        $this->assertSame(1, $clone->afterFetchCount);
        $this->assertSame(
            [
                'dirtyState' => Model::DIRTY_STATE_PERSISTENT,
                'inv_id'     => 7,
                'inv_title'  => 'fetched title',
            ],
            $clone->afterFetchSnapshot
        );
    }

    /**
     * afterFetch() fires on the returned clone and never on the base record.
     */
    public function testMvcModelCloneResultAfterFetchFiresOnCloneNotBase(): void
    {
        $base = new InvoicesCloneResultProbe();

        $clone = Model::cloneResult($base, ['inv_id' => 1]);

        $this->assertSame(0, $base->afterFetchCount);
        $this->assertSame(1, $clone->afterFetchCount);
    }

    /**
     * An empty $data array still produces a clone and still fires afterFetch().
     */
    public function testMvcModelCloneResultAfterFetchFiresWithEmptyData(): void
    {
        $clone = Model::cloneResult(new InvoicesCloneResultProbe(), []);

        $this->assertSame(1, $clone->afterFetchCount);
    }

    /**
     * The $dirtyState argument defaults to 0 (DIRTY_STATE_PERSISTENT).
     */
    public function testMvcModelCloneResultDirtyStateDefaultsToPersistent(): void
    {
        $clone = Model::cloneResult(new Invoices(), ['inv_id' => 1]);

        $this->assertSame(Model::DIRTY_STATE_PERSISTENT, $clone->getDirtyState());
    }

    /**
     * An explicit $dirtyState is stored verbatim.
     */
    public function testMvcModelCloneResultDirtyStateHonorsExplicitValue(): void
    {
        $clone = Model::cloneResult(
            new Invoices(),
            ['inv_id' => 1],
            Model::DIRTY_STATE_DETACHED
        );

        $this->assertSame(Model::DIRTY_STATE_DETACHED, $clone->getDirtyState());
    }

    /**
     * setDirtyState() runs BEFORE the assignment loop: a setter invoked while
     * assignment is still running already observes the new dirty state, not the
     * constructor default of DIRTY_STATE_TRANSIENT.
     */
    public function testMvcModelCloneResultDirtyStateSetBeforeAssignment(): void
    {
        $clone = Model::cloneResult(
            new InvoicesCloneResultProbe(),
            ['probeValue' => 'anything'],
            Model::DIRTY_STATE_DETACHED
        );

        $this->assertSame(
            [Model::DIRTY_STATE_DETACHED],
            $clone->setterDirtyStates
        );
    }

    /**
     * The invalid-key check happens inside the assignment loop, so afterFetch()
     * never fires when a key is rejected.
     */
    public function testMvcModelCloneResultDoesNotFireAfterFetchOnInvalidKey(): void
    {
        $base = new InvoicesCloneResultProbe();

        try {
            Model::cloneResult($base, [0 => 'value']);
            $this->fail('InvalidDumpResultKey was not thrown');
        } catch (InvalidDumpResultKey $ex) {
            $this->assertSame(0, $base->afterFetchCount);
        }
    }

    /**
     * A DECLARED public property is written directly, so a matching setter is
     * never consulted - the opposite of the undeclared case above.
     */
    public function testMvcModelCloneResultDoesNotInvokeSetterForDeclaredProperty(): void
    {
        $clone = Model::cloneResult(
            new InvoicesCloneResultProbe(),
            ['inv_title' => 'written directly']
        );

        $this->assertSame(0, $clone->declaredSetterCalls);
        $this->assertSame('written directly', $clone->inv_title);
    }

    /**
     * The base record is never touched - not its properties, not its dirty
     * state, not its events.
     */
    public function testMvcModelCloneResultDoesNotMutateBase(): void
    {
        $base            = new InvoicesCloneResultProbe();
        $base->inv_title = 'base title';

        $clone = Model::cloneResult(
            $base,
            ['inv_title' => 'clone title'],
            Model::DIRTY_STATE_PERSISTENT
        );

        $this->assertSame('base title', $base->inv_title);
        $this->assertSame(Model::DIRTY_STATE_TRANSIENT, $base->getDirtyState());
        $this->assertSame(0, $base->afterFetchCount);
        $this->assertSame('clone title', $clone->inv_title);
        $this->assertNotSame($base, $clone);
    }

    /**
     * An undeclared property routes through Model::__set(), so possibleSetter()
     * invokes a matching setter instead of writing the property.
     */
    public function testMvcModelCloneResultInvokesSetterForUndeclaredProperty(): void
    {
        $clone = Model::cloneResult(
            new InvoicesCloneResultProbe(),
            ['probeValue' => 'anything']
        );

        $this->assertCount(1, $clone->setterDirtyStates);
    }

    /**
     * Values already on the base record survive onto the clone when $data does
     * not carry that key.
     */
    public function testMvcModelCloneResultKeepsBasePropertiesAbsentFromData(): void
    {
        $base            = new Invoices();
        $base->inv_total = 99.5;

        $clone = Model::cloneResult($base, ['inv_title' => 'only the title']);

        $this->assertSame(99.5, $clone->inv_total);
        $this->assertSame('only the title', $clone->inv_title);
    }

    /**
     * fireEvent() also reaches the models manager, so a `model:afterFetch`
     * listener fires exactly once and receives the clone as the event source.
     */
    public function testMvcModelCloneResultNotifiesEventsManager(): void
    {
        $fired = [];

        $eventsManager = new EventsManager();
        $eventsManager->attach(
            'model:afterFetch',
            function ($event, $model) use (&$fired) {
                $fired[] = $model;
            }
        );

        $this->container->get('modelsManager')
                        ->setEventsManager($eventsManager);

        $clone = Model::cloneResult(
            new InvoicesCloneResultProbe(),
            ['inv_id' => 3]
        );

        $this->assertCount(1, $fired);
        $this->assertSame($clone, $fired[0]);
    }

    /**
     * The clone keeps the concrete class of the base record, even when
     * cloneResult() is reached through Phalcon\Mvc\Model itself.
     */
    public function testMvcModelCloneResultPreservesSubclassType(): void
    {
        $clone = Model::cloneResult(
            new InvoicesWithPrivateSetters(),
            ['inv_id' => 1]
        );

        $this->assertInstanceOf(InvoicesWithPrivateSetters::class, $clone);
    }

    /**
     * Tests that cloneResult() does NOT call the setter of a private property
     * during hydration; the raw DB value must be written directly.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16454
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-16
     */
    public function testMvcModelCloneResultPrivateDoesNotCallSetter(): void
    {
        /** @var InvoicesWithPrivateSetters $clone */
        $clone = Model::cloneResult(
            new InvoicesWithPrivateSetters(),
            [
                'inv_id'      => 5,
                'secretValue' => 'raw-db-value',
            ]
        );

        // The private property receives the raw value - no 'SETTER:' prefix.
        $this->assertSame('raw-db-value', $clone->getSecretValue());
    }

    /**
     * A non-string key is rejected, and the message names the base class.
     */
    public function testMvcModelCloneResultThrowsOnNonStringKey(): void
    {
        $this->expectException(InvalidDumpResultKey::class);
        $this->expectExceptionMessage(
            "Invalid key in array data provided to dumpResult() in '"
            . Invoices::class
            . "'"
        );

        Model::cloneResult(new Invoices(), [0 => 'value']);
    }

    /**
     * PHP normalizes a numeric string key to an integer before cloneResult()
     * sees it, so '5' is rejected exactly like 5.
     */
    public function testMvcModelCloneResultThrowsOnNumericStringKey(): void
    {
        $this->expectException(InvalidDumpResultKey::class);

        Model::cloneResult(new Invoices(), ['5' => 'value']);
    }

    /**
     * A private property with no getter or setter is still written directly by
     * reflection - the write does not fall back to __set().
     */
    public function testMvcModelCloneResultWritesPrivatePropertyWithoutAccessors(): void
    {
        $clone = Model::cloneResult(
            new Invoices(),
            ['superSecret' => 'hidden']
        );

        $property = new ReflectionProperty(Invoices::class, 'superSecret');
        $property->setAccessible(true);

        $this->assertSame('hidden', $property->getValue($clone));
    }

    /**
     * A typed private property is written raw through reflection; its setter is
     * not invoked and the value is not coerced.
     */
    public function testMvcModelCloneResultWritesTypedPrivatePropertyWithoutSetter(): void
    {
        $clone = Model::cloneResult(
            new InvoicesCloneResultProbe(),
            ['isActive' => false]
        );

        $this->assertFalse($clone->getIsActive());
        $this->assertSame(0, $clone->typedSetterCalls);
    }
}
