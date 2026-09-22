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

namespace Phalcon\Tests\Support\Models\Annotations;

use Phalcon\Annotations\Models\MetaData\Column;
use Phalcon\Annotations\Models\MetaData\Identity;
use Phalcon\Annotations\Models\MetaData\Primary;
use Phalcon\Mvc\Model;

/**
 * Model for the MetaData Annotations strategy tests. Every property carries
 * the docblock annotation and the attribute that say the same thing, so the
 * model serves both readers. The docblock uses the snake_case argument names
 * that the strategy reads; the attribute uses the camelCase constructor
 * parameters.
 */
class Robot extends Model
{
    /**
     * @Primary
     * @Identity
     * @Column(type="biginteger")
     */
    #[Primary]
    #[Identity]
    #[Column(type: 'biginteger')]
    protected $id;

    /**
     * @Column(type="varchar", length=70, allow_empty_string=true)
     */
    #[Column(type: 'varchar', length: 70, allowEmptyString: true)]
    protected $name;

    /**
     * @Column(type="varchar", length=32, default="mechanical")
     */
    #[Column(type: 'varchar', length: 32, defaultValue: 'mechanical')]
    protected $type;

    /**
     * @Column(type="integer", default=1900)
     */
    #[Column(type: 'integer', defaultValue: 1900)]
    protected $year;

    /**
     * @Column(type="datetime", nullable=true, skip_on_insert=true)
     */
    #[Column(type: 'datetime', nullable: true, skipOnInsert: true)]
    protected $deleted;

    /**
     * @Column(type="text", column="text", allow_empty_string=true)
     */
    #[Column(type: 'text', column: 'text', allowEmptyString: true)]
    protected $description;

    /**
     * @Column(type="float", skip_on_update=true)
     */
    #[Column(type: 'float', skipOnUpdate: true)]
    protected $float;

    /**
     * @Column(type="double")
     */
    #[Column(type: 'double')]
    protected $double;

    /**
     * @Column(type="decimal")
     */
    #[Column(type: 'decimal')]
    protected $decimal;

    /**
     * @Column(type="boolean")
     */
    #[Column(type: 'boolean')]
    protected $activated;

    /**
     * @Column(type="date")
     */
    #[Column(type: 'date')]
    protected $birthday;

    /**
     * @Column(type="timestamp")
     */
    #[Column(type: 'timestamp')]
    protected $timestamp;

    /**
     * @Column(type="time")
     */
    #[Column(type: 'time')]
    protected $duration;

    /**
     * @Column(type="char", length=10)
     */
    #[Column(type: 'char', length: 10)]
    protected $code;

    /**
     * @Column(type="bit")
     */
    #[Column(type: 'bit')]
    protected $bit;

    /**
     * @Column(type="enum")
     */
    #[Column(type: 'enum')]
    protected $enum;

    /**
     * @Column(type="tinyint")
     */
    #[Column(type: 'tinyint')]
    protected $tinyint;

    /**
     * @Column(type="smallint")
     */
    #[Column(type: 'smallint')]
    protected $smallint;

    /**
     * @Column(type="mediumint")
     */
    #[Column(type: 'mediumint')]
    protected $mediumint;

    /**
     * @Column(type="tinytext")
     */
    #[Column(type: 'tinytext')]
    protected $tinytext;

    /**
     * @Column(type="mediumtext")
     */
    #[Column(type: 'mediumtext')]
    protected $mediumtext;

    /**
     * @Column(type="longtext")
     */
    #[Column(type: 'longtext')]
    protected $longtext;

    /**
     * @Column(type="json", nullable=true)
     */
    #[Column(type: 'json', nullable: true)]
    protected $json;

    /**
     * @Column(type="jsonb", nullable=true)
     */
    #[Column(type: 'jsonb', nullable: true)]
    protected $jsonb;

    /**
     * @Column(type="tinyblob", nullable=true)
     */
    #[Column(type: 'tinyblob', nullable: true)]
    protected $tinyblob;

    /**
     * @Column(type="blob", nullable=true)
     */
    #[Column(type: 'blob', nullable: true)]
    protected $blob;

    /**
     * @Column(type="mediumblob", nullable=true)
     */
    #[Column(type: 'mediumblob', nullable: true)]
    protected $mediumblob;

    /**
     * @Column(type="longblob", nullable=true, skip_on_update=true)
     */
    #[Column(type: 'longblob', nullable: true, skipOnUpdate: true)]
    protected $longblob;
}
