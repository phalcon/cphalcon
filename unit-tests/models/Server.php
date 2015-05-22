<?php


class Server extends Phalcon\Mvc\Model
{
	public $name;

	protected $ip;

	private $mac;

	public function setIp($value) {
		$this->ip = str_replace('-', '.', $value);
	}

	public function getIp() {
		return $this->ip;
	}

	public function getMac() {
		return str_replace('-', '0', $this->mac);
	}
}