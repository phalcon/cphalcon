<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Boutique;

use Phalcon\Mvc\Model;

class Robots extends Model
{
    const setterEpilogue = ' setText';

    /**
     * @Primary
     * @Identity
     * @Column(type="integer", nullable=false)
     */
    public $id;

    /**
     * @Column(type="string", length=70, nullable=false)
     */
    public $name;

    /**
     * @Column(type="string", length=32, nullable=false, default='mechanical')
     */
    public $type;

    /**
     * @Column(type="integer", nullable=false, default=1900)
     */
    public $year;

    /**
     * @Column(type="datetime", nullable=false)
     */
    public $datetime;

    /**
     * @Column(type="datetime", nullable=true)
     */
    public $deleted;

    /**
     * @Column(type="text", nullable=false)
     */
    protected $text;

    /**
     * Test restriction to not set hidden properties without setters.
     */
    protected $serial;

    public function getText()
    {
        return $this->text;
    }

    public function setText($value)
    {
        return ($this->text = $value . self::setterEpilogue);
    }
}
