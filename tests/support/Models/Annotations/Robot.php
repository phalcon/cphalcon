<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Support\Models\Annotations;

use Phalcon\Annotations\Models\MetaData\Column;
use Phalcon\Annotations\Models\MetaData\Identity;
use Phalcon\Annotations\Models\MetaData\Primary;
use Phalcon\Mvc\Model;

class Robot extends Model
{
    #[Primary]
    #[Identity]
    #[Column(type: 'biginteger')]
    protected $id;

    #[Column(type: 'varchar', length: 70, allowEmptyString: true)]
    protected $name;

    #[Column(type: 'varchar', length: 32, default: 'mechanical')]
    protected $type;

    #[Column(type: 'integer', default: 1900)]
    protected $year;

    #[Column(type: 'datetime', nullable: true, skipOnInsert: true)]
    protected $deleted;

    #[Column(type: 'text', column: 'text', allowEmptyString: true)]
    protected $description;

    #[Column(type: 'float', skipOnUpdate: true)]
    protected $float;

    #[Column(type: 'double')]
    protected $double;

    #[Column(type: 'decimal')]
    protected $decimal;

    #[Column(type: 'boolean')]
    protected $activated;

    #[Column(type: 'date')]
    protected $birthday;

    #[Column(type: 'timestamp')]
    protected $timestamp;

    #[Column(type: 'char', length: 10)]
    protected $code;

    #[Column(type: 'json', nullable: true)]
    protected $json;

    #[Column(type: 'tinyblob', nullable: true)]
    protected $tinyblob;

    #[Column(type: 'blob', nullable: true)]
    protected $blob;

    #[Column(type: 'mediumblob', nullable: true)]
    protected $mediumblob;

    #[Column(type: 'longblob', nullable: true, skipOnUpdate: true)]
    protected $longblob;
}
