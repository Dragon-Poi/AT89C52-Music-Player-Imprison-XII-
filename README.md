# AT89C52 Music Player – Imprison XII  
AT89C52 单片机音乐播放器 – Imprison XII

## 简介 / Introduction
本项目基于 **普中 A2 开发板**，使用 **AT89C52 单片机** 播放乐曲 *Imprison XII*。  
This project is based on the **PuZhong A2 development board**, using the **AT89C52 MCU** to play the music piece *Imprison XII*.  

该项目主要作为单片机学习的实践，参考了 **bilibili 江协科技** 的课程。  
This project is for learning purposes, inspired by the tutorial series from **Bilibili JiangXie Technology**.  

---

## 功能特点 / Features
- 使用 AT89C52 实现乐曲播放  
- 提供可直接下载的 **HEX 文件**  
- 支持在 **Keil uVision5** 中自行编译源码  
- 硬件电路简单：开发板 + 蜂鸣器即可输出音乐  

---

## 硬件需求 / Hardware Requirements
- 普中 A2 开发板（STC89C52/AT89C52 MCU）  
- 蜂鸣器 / 小音箱  
- Micro USB 转串口（用于下载 HEX 文件）  

---

## 使用方法 / How to Use
1. **直接导入 HEX 文件**  
   - 打开 **STC ISP 下载软件**  
   - 将提供的 `.hex` 文件导入开发板  
   - 上电后即可播放音乐  

2. **自行编译源码**  
   - 使用 **Keil uVision5** 打开源码  
   - 编译生成 `.hex` 文件  
   - 使用 STC 软件下载到开发板  

---

## 成品演示 / Demo
👉 [演示视频] https://www.bilibili.com/video/BV1eVarzqEiM/?share_source=copy_web&vd_source=47b2cca0c4d4b27b476037c3f69259e5

---

## 参考课程 / Reference
本项目参考了 **bilibili 江协科技** 的单片机教学视频：  
👉 [课程链接] https://www.bilibili.com/video/BV1Mb411e7re?spm_id_from=333.788.videopod.episodes&vd_source=7a541018eb5ebc845239fd84603bcc6b&p=25

---

## License
MIT License
