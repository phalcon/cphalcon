<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Model\Query\Lang;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Query;
use Phalcon\Mvc\Model\Query\Lang;
use Phalcon\Support\Settings;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DebugBuildTrait;
use ReflectionProperty;

use function array_fill;
use function implode;
use function ini_get;
use function ini_set;
use function memory_get_usage;
use function microtime;
use function property_exists;
use function str_repeat;

use const PHP_INT_MAX;
use const PHP_INT_MIN;

/**
 * Lang::parsePHQL() keeps the AST of each statement, with the exact statement
 * as the key, and tags it with an `id` from a counter that starts at
 * `orm.unique_cache_id`. A parse error is a Phalcon\Mvc\Model\Exception
 * (ext/phalcon/mvc/model/query/base.c, phql_parse_phql()).
 *
 * The cache lives until Query::clean(). tearDown() calls it, and each test
 * uses statements of its own.
 */
final class ParsePHQLTest extends AbstractUnitTestCase
{
    use DebugBuildTrait;

    /**
     * The ini values that tearDown() restores, by setting.
     *
     * @var array<string, string>
     */
    private array $iniValues = [];

    public function tearDown(): void
    {
        foreach ($this->iniValues as $key => $value) {
            ini_set('phalcon.' . $key, $value);
        }

        $this->iniValues = [];

        Settings::reset();
        Query::clean();

        parent::tearDown();
    }

    /**
     * Query::clean() drops the parsed statements along with the intermediate
     * representations cached under their ids.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-07
     */
    public function testMvcModelQueryCleanAlsoForgetsCachedStatements(): void
    {
        $before = Lang::parsePHQL('SELECT * FROM QueryClean')['id'] ?? null;
        Query::clean();
        $after = Lang::parsePHQL('SELECT * FROM QueryClean')['id'] ?? null;

        $this->assertIsInt($before);
        $this->assertGreaterThan($before, $after);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-07
     */
    public function testMvcModelQueryLangParsePHQLBlankStatementHasNoResult(): void
    {
        $this->skipOnDebugBuild();

        $this->assertSame([null, null], [Lang::parsePHQL(''), Lang::parsePHQL(' ')]);
    }

    /**
     * Tests that two PHQL strings which previously collided under
     * zend_inline_hash_func produce distinct AST representations.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheCollision(): void
    {
        $phql1 = "SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* "
               . "FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] "
               . "WHERE _id = 'GcbN9FIoI8IC3LqBIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:";

        $phql2 = "SELECT [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users].* "
               . "FROM [TagMe\Modules\Identity\Infrastructure\User\Model\Elasticsearch\Users] "
               . "WHERE _id = 'GcbN9FIoI8IC3LpcIuCu50AC02TpI8ruKOjyzd1fqOCuna' LIMIT :APL0:";

        $ast1 = Lang::parsePHQL($phql1);
        $ast2 = Lang::parsePHQL($phql2);

        $this->assertNotSame($ast1, $ast2);

        // Each query must keep its own `_id`, not the other's cached value.
        $this->assertSame(
            'GcbN9FIoI8IC3LqBIuCu50AC02TpI8ruKOjyzd1fqOCuna',
            $ast1['where']['right']['value']
        );
        $this->assertSame(
            'GcbN9FIoI8IC3LpcIuCu50AC02TpI8ruKOjyzd1fqOCuna',
            $ast2['where']['right']['value']
        );
    }

    /**
     * A second, independent minimal collision pair, easier to verify than the
     * 47-character id from the issue. 'B0' and 'AQ' collide under DJBX33A:
     * 33 * 66 + 48 == 33 * 65 + 81.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheCollisionMinimal(): void
    {
        $phql1 = "SELECT * FROM Robots WHERE name = 'B0'";
        $phql2 = "SELECT * FROM Robots WHERE name = 'AQ'";

        $ast1 = Lang::parsePHQL($phql1);
        $ast2 = Lang::parsePHQL($phql2);

        $this->assertSame('B0', $ast1['where']['right']['value']);
        $this->assertSame('AQ', $ast2['where']['right']['value']);
    }

    /**
     * The colliding query parsed second must keep its own value regardless of
     * parse order - the bug poisons whichever query populates the cache first.
     * 'qB' and 'pc' collide under DJBX33A: 33 * 113 + 66 == 33 * 112 + 99.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheCollisionParseOrder(): void
    {
        $phql1 = "SELECT * FROM Robots WHERE name = 'qB'";
        $phql2 = "SELECT * FROM Robots WHERE name = 'pc'";

        // Parse the second one first to prove neither order poisons the cache.
        $ast2 = Lang::parsePHQL($phql2);
        $ast1 = Lang::parsePHQL($phql1);

        $this->assertSame('pc', $ast2['where']['right']['value']);
        $this->assertSame('qB', $ast1['where']['right']['value']);
    }

    /**
     * Literals are checked while parsing; a statement already in the cache
     * is returned as it was parsed, whatever `orm.enable_literals` is now.
     * cphalcon 5.23.0 with the same steps: the first parse gets an id, the
     * second returns the same AST (same id), the third throws "Literals are
     * disabled in PHQL statements".
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-07
     */
    public function testMvcModelQueryLangParsePHQLCacheHitBypassesLiteralCheck(): void
    {
        $cached = Lang::parsePHQL("SELECT * FROM LiteralBypass WHERE a = 'x'");

        $this->setOrmSetting('orm.enable_literals', false);

        $this->assertSame($cached, Lang::parsePHQL("SELECT * FROM LiteralBypass WHERE a = 'x'"));

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Literals are disabled in PHQL statements');

        Lang::parsePHQL("SELECT * FROM LiteralBypass WHERE a = 'y'");
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-07
     */
    public function testMvcModelQueryLangParsePHQLCacheLevelMinusOneHasNoId(): void
    {
        $this->setOrmSetting('orm.cache_level', -1);

        $this->assertArrayNotHasKey('id', Lang::parsePHQL('SELECT * FROM CacheLevelMinusOne') ?? []);
    }

    /**
     * Level 0 caches without an id; the cached AST keeps having none.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-07
     */
    public function testMvcModelQueryLangParsePHQLCacheLevelZeroCachesWithoutId(): void
    {
        $this->setOrmSetting('orm.cache_level', 0);
        $first = Lang::parsePHQL('SELECT * FROM CacheLevelZero');

        $this->setOrmSetting('orm.cache_level', 3);
        $second = Lang::parsePHQL('SELECT * FROM CacheLevelZero');

        $this->assertSame([false, $first], [isset($first['id']), $second]);
    }

    /**
     * The same PHQL parsed twice must return an equal AST - a cache hit for a
     * matching key must yield the correct representation.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-05
     * @issue  https://github.com/phalcon/cphalcon/issues/14791
     */
    public function testMvcModelQueryLangParsePHQLCacheReturnsSameAst(): void
    {
        $phql = "SELECT * FROM Robots WHERE name = 'cacheHit'";

        $ast1 = Lang::parsePHQL($phql);
        $ast2 = Lang::parsePHQL($phql);

        $this->assertSame($ast1, $ast2);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-07
     */
    public function testMvcModelQueryLangParsePHQLErrorsAreModelExceptions(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Syntax error, unexpected token EQUALS, near to ' 1', "
            . 'when parsing: SELECT * FROM ParseErrors WHERE id = = 1 (40)'
        );

        Lang::parsePHQL('SELECT * FROM ParseErrors WHERE id = = 1');
    }

    /**
     * The scanner must resolve the escape sequences of a string literal, so
     * that the dialect receives the real characters and escapes them for its
     * own syntax. An unknown sequence keeps its backslash, the same as MySQL
     * and PHP do, so a LIKE pattern such as "100\%" still matches a percent
     * sign.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-09
     * @issue  https://github.com/phalcon/cphalcon/issues/17585
     */
    public function testMvcModelQueryLangParsePHQLEscapeSequencesInString(): void
    {
        // PHQL sequence => the characters it stands for
        $expected = [
            '\n'   => "\n",
            '\r'   => "\r",
            '\t'   => "\t",
            '\\\\' => '\\',
            "\\'"  => "'",
            '\"'   => '"',
            '\%'   => '\%',
            '\d'   => '\d',
        ];

        foreach ($expected as $sequence => $value) {
            $ast = Lang::parsePHQL(
                "SELECT * FROM Robots WHERE name = 'a" . $sequence . "b'"
            );

            $this->assertSame(
                'a' . $value . 'b',
                $ast['where']['right']['value'],
                $sequence
            );
        }
    }

    /**
     * Ids come from one counter; a cached statement keeps its id.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-07
     */
    public function testMvcModelQueryLangParsePHQLIdRepeatsOnCacheHit(): void
    {
        $first  = Lang::parsePHQL('SELECT * FROM IdSequenceOne')['id'] ?? null;
        $again  = Lang::parsePHQL('SELECT * FROM IdSequenceOne')['id'] ?? null;
        $second = Lang::parsePHQL('SELECT * FROM IdSequenceTwo')['id'] ?? null;

        $this->assertIsInt($first);
        $this->assertSame([$first, $first + 1], [$again, $second]);
    }

    /**
     * The id counter wraps from PHP_INT_MAX to PHP_INT_MIN, and the parser
     * continues to work.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testMvcModelQueryLangParsePHQLIdWrapsAtMaximum(): void
    {
        $this->setIdCounter(PHP_INT_MAX);

        $actual = [
            Lang::parsePHQL('SELECT * FROM IdWrapOne')['id'] ?? null,
            Lang::parsePHQL('SELECT * FROM IdWrapTwo')['id'] ?? null,
            Lang::parsePHQL('SELECT * FROM IdWrapThree')['id'] ?? null,
        ];

        $this->assertSame([PHP_INT_MAX, PHP_INT_MIN, PHP_INT_MIN + 1], $actual);
    }

    /**
     * The IN list is built in linear time; 40,000 items used to take
     * seconds.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelQueryLangParsePHQLLargeInList(): void
    {
        $count = 40000;
        $phql  = 'SELECT * FROM Robots WHERE id IN ('
            . implode(',', array_fill(0, $count, '1')) . ')';

        $start  = microtime(true);
        $actual = Lang::parsePHQL($phql);
        $spent  = microtime(true) - $start;

        $this->assertIsArray($actual);
        $this->assertLessThan(3.0, $spent);
    }

    /**
     * Model::setup() keeps `phqlLiterals` in Settings only. The parser must
     * read it from Settings, not from the ini value.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     * @issue  https://github.com/phalcon/cphalcon/issues/17797
     */
    public function testMvcModelQueryLangParsePHQLModelSetupLiterals(): void
    {
        $phql = 'SELECT * FROM SetupLiterals WHERE id = 1';

        Model::setup(['phqlLiterals' => false]);

        $caught = null;

        try {
            Lang::parsePHQL($phql);
        } catch (Exception $ex) {
            $caught = $ex;
        }

        $this->assertNotNull($caught);
        $this->assertSame('Literals are disabled in PHQL statements', $caught->getMessage());

        Model::setup(['phqlLiterals' => true]);

        $this->assertIsArray(Lang::parsePHQL($phql));
    }

    /**
     * With literals disabled the scanner still allocates the literal token;
     * the parser must release it when it rejects the statement.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelQueryLangParsePHQLRejectedLiteralDoesNotLeak(): void
    {
        $this->setOrmSetting('orm.enable_literals', false);

        $phql     = 'SELECT * FROM Robots WHERE name = "' . str_repeat('x', 1000) . '"';
        $rejected = 0;
        $before   = memory_get_usage();

        for ($i = 0; $i < 5000; $i++) {
            try {
                Lang::parsePHQL($phql);
            } catch (Exception $ex) {
                // Expected: literals are disabled.
                $rejected++;
            }
        }

        $delta = memory_get_usage() - $before;

        $this->assertSame(5000, $rejected);

        // 5,000 x 1 KB literals leaked ~5.5 MB before the fix.
        $this->assertLessThan(1048576, $delta);
    }

    /**
     * The parser must read `orm.cache_level` from Settings, not from the ini
     * value. With -1, the AST has no id.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     * @issue  https://github.com/phalcon/cphalcon/issues/17797
     */
    public function testMvcModelQueryLangParsePHQLSettingsCacheLevel(): void
    {
        Settings::set('orm.cache_level', -1);

        $this->assertArrayNotHasKey('id', Lang::parsePHQL('SELECT * FROM SettingsCacheLevel') ?? []);
    }

    /**
     * A backslash as the last byte of a quoted string must be a scanning
     * error, not an escape that swallows the terminator.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcModelQueryLangParsePHQLTrailingBackslashInString(): void
    {
        foreach (['"abc\\', "'abc\\"] as $literal) {
            $caught = null;

            try {
                Lang::parsePHQL('SELECT * FROM Robots WHERE name = ' . $literal);
            } catch (Exception $ex) {
                $caught = $ex;
            }

            $this->assertNotNull($caught, $literal);
            $this->assertStringContainsString('Scanning error', $caught->getMessage());
        }
    }

    /**
     * Sets the next id of the parser. The C parser of cphalcon reads the
     * counter from the ini value. phalcon reads the setting one time only,
     * then keeps the counter in the private Lang::$nextId property.
     */
    private function setIdCounter(int $value): void
    {
        $this->setOrmSetting('orm.unique_cache_id', $value);

        if (property_exists(Lang::class, 'nextId')) {
            (new ReflectionProperty(Lang::class, 'nextId'))->setValue(null, $value);
        }
    }

    /**
     * Changes an ORM setting in the two places that the projects read it:
     * Settings (phalcon) and the ini value (the C parser of cphalcon). In
     * each project, the other call has no effect. tearDown() restores both.
     */
    private function setOrmSetting(string $key, bool | int $value): void
    {
        $previous = ini_get('phalcon.' . $key);
        if (false !== $previous && !isset($this->iniValues[$key])) {
            $this->iniValues[$key] = $previous;
        }

        ini_set('phalcon.' . $key, (string) (int) $value);
        Settings::set($key, $value);
    }
}
