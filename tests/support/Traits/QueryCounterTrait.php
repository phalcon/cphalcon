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

namespace Phalcon\Tests\Support\Traits;

use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Events\Event;
use Phalcon\Events\Manager as EventsManager;

/**
 * Records every statement the connection issues so tests can assert how many
 * queries a block of code costs.
 *
 * Counting queries is the only assertion that distinguishes a working eager
 * load from a lazy one that happens to return the same data - the returned
 * data is identical either way, only the number of round trips differs.
 *
 * Holding the statements rather than a bare tally means a failure reports the
 * SQL that actually ran, and lets the row-count probe below be recognised
 * instead of skewing the total.
 */
trait QueryCounterTrait
{
    /**
     * Statement PdoResult::numRows() issues when the adapter cannot report a
     * row count from the original statement - SQLite. It is an artefact of
     * asking for the count, not a query the code under test made, so it is
     * excluded from the total. See PdoResult::numRows().
     *
     * Tests that are about the probe itself - rather than about the code that
     * happens to trigger it - want it counted, and use the "raw" accessors
     * below instead.
     *
     * A static property rather than a constant: traits cannot declare
     * constants before PHP 8.2 and the suite runs on 8.1.
     */
    private static string $rowCountProbe = 'SELECT COUNT(*) "numrows" FROM (';

    /**
     * Every statement seen since the listener was attached, in order.
     *
     * @var array<int, string>
     */
    protected array $recordedQueries = [];

    /**
     * Asserts the number of queries issued since the listener was attached.
     */
    protected function assertQueryCount(int $expected): void
    {
        $queries = $this->getQueries();

        $this->assertCount(
            $expected,
            $queries,
            sprintf(
                "Expected %d queries, got %d:\n%s",
                $expected,
                count($queries),
                implode("\n", $queries)
            )
        );
    }

    /**
     * Asserts the number of statements issued since the listener was attached,
     * counting the row-count probe.
     */
    protected function assertRawQueryCount(int $expected): void
    {
        $queries = $this->getAllQueries();

        $this->assertCount(
            $expected,
            $queries,
            sprintf(
                "Expected %d statements, got %d:\n%s",
                $expected,
                count($queries),
                implode("\n", $queries)
            )
        );
    }

    /**
     * Starts recording. Discards anything recorded previously.
     *
     * @param AdapterInterface $connection connection to observe
     */
    protected function attachQueryCounter(AdapterInterface $connection): void
    {
        $this->recordedQueries = [];

        $eventsManager = new EventsManager();

        $eventsManager->attach(
            'db',
            function (Event $event, $connection) {
                if ('beforeQuery' === $event->getType()) {
                    $this->recordedQueries[] = $connection->getSQLStatement();
                }
            }
        );

        $connection->setEventsManager($eventsManager);
    }

    /**
     * Every statement issued, in order, including the row-count probe.
     *
     * @return array<int, string>
     */
    protected function getAllQueries(): array
    {
        return $this->recordedQueries;
    }

    /**
     * Statements issued by the code under test, in order.
     *
     * @return array<int, string>
     */
    protected function getQueries(): array
    {
        return array_values(
            array_filter(
                $this->recordedQueries,
                function (string $query) {
                    return !str_starts_with(
                        trim($query),
                        self::$rowCountProbe
                    );
                }
            )
        );
    }

    /**
     * Number of queries issued by the code under test.
     */
    protected function getQueryCount(): int
    {
        return count($this->getQueries());
    }

    /**
     * Number of row-count probes issued since the listener was attached.
     */
    protected function getRowCountProbeCount(): int
    {
        return count($this->getAllQueries()) - count($this->getQueries());
    }

    /**
     * Forces each model to load its MetaData before recording starts.
     *
     * The first use of a model issues DESCRIBE-style statements to build its
     * column map. Those are real statements on the same connection, so leaving
     * them inside the recorded window inflates every count by a fixed amount
     * per model and hides the number under test.
     *
     * @param array<int, class-string> $models
     */
    protected function warmMetaData(array $models): void
    {
        foreach ($models as $model) {
            $model::findFirst('1 = 0');
        }
    }
}
